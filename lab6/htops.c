#include<stdio.h>
#include<stdlib.h>
#define SIZE_T 100
#define CSIZE 50
#include "hashtable.h"
#include "htops.h"

Hash_item* populate_Hashtable( char * filename){
	
	printf("in populate\n");
	FILE* fp = fopen(filename,"r");
	
	Hash_item* Hash_item_ptr = (Hash_item*)malloc(SIZE_T*sizeof(Hash_item));

	int flag_item[SIZE_T] = {0};
	
	int i;
	for ( i = 0 ; !feof(fp) ; i++ ){	
		
		node temp;
		fscanf(fp,"%d %s %d\n",&temp.cust_id,temp.item_id,&temp.item_cost);
		temp.next = NULL;

		int val1 = hash1(temp.item_id,SIZE_T);
		
		
		
		if ( flag_item[val1] == 0 ){
			
			Hash_item_ptr[val1].n = temp;
			flag_item[val1] = 1;
			
			Hash_id* p_Hash_id = (Hash_id*)malloc(CSIZE*sizeof(Hash_id));
			Hash_item_ptr[val1].ptr_Hash_id = p_Hash_id;
			
		
		}

		else {
			int val2 = hash2(temp.cust_id,CSIZE);
			
				
			node* tempx = Hash_item_ptr[val1].ptr_Hash_id[val2].ptr;
				 
			Hash_item_ptr[val1].ptr_Hash_id[val2].ptr = &temp;
			temp.next  = tempx;
			
		}


	}

	return Hash_item_ptr;

}

int hash1(char key[],int size){
	
	int i = 0;
	char c = key[0];
	int sum = 0;

	while ( c != '\0' ){
		sum += (int)c;
		i++;
		c = key[i];	
		}

	return ((sum%113)%size);

}


int hash2(int key,int size){

	int sum = 0;
	
	while ( key != 0 ){
		
		sum += key%10;
		key /= 10;
	}

	return sum%size;

}

void printHT(Hash_item* ht,int htsize,FILE* fp){
	
	int i = 0;

	
	while ( i < htsize/2 ){
		
		node temp = ht[i].n;
	
			
			fprintf(fp,"%d %s %d\n",temp.cust_id,temp.item_id,temp.item_cost);
			
			/*Hash_id* cool = ht[i].ptr_Hash_id;
			int j = 0;
			while ( j < CSIZE ){
				node* t = cool[j++].ptr;
				printf("hi\n");
				while ( t->next != NULL ){
					printf("bi\n");
					fprintf(fp,"hashTable 2\n");
					fprintf(fp,"%d %s %d\n",t->cust_id,t->item_id,t->item_cost);
				}	t = t->next;
			
			}*/
	i++;
	}
	


}

	
	






