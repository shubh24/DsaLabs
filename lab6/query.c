#include<stdio.h>
#define SIZE_T 100
#define SIZE_C 50

#include "hashtable.h"
#include "htops.h"

int main(int argc,char* argv[]){
	
	Hash_item* head = populate_Hashtable(argv[1]);
	
	FILE* fp = fopen("output.txt","w");
	printHT(head,SIZE_T,fp);
}
