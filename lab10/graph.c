#include<stdio.h>
#include<stdlib.h>

typedef struct list{
struct node* child;
struct list* next;
}list;

typedef struct node{
int n;
int done;
struct list* ptr;
}node;

list* createList(int arr[][6],node* nodearr[6],int number){

list* l1 = (list*)malloc(sizeof(list));

if ( nodearr[number] == NULL )
	l1->child = createNode(arr,number,nodearr);
else
	l1->child = nodearr[number];

l1->next = NULL;

return l1;
}

void addToList(int arr[][6],list* l1,node* nodearr[6],int number){

	list* temp = l1;
	while ( temp->next!=NULL )
		temp = temp->next;
	temp->next = createList(arr,nodearr,number);

}


node* createNode(int arr[][6],int posn,node* nodearr[6]){

node* n1 =(node*)malloc(sizeof(node));

n1->n = posn;
n1->done = 0;

int i;

n1->ptr = createList(arr,nodearr,0);

for ( i = 0 ; i < 6 ; i++ ){
	
	if ( arr[posn][i] != 0 ){
		
		addToList(arr,n1->ptr,nodearr,i);
	}
}
	
return n1;

}

int main(){

int arr[6][6] = {{0,17,28,0,25,0},{17,0,30,27,0,0},{28,30,0,0,11,35},{0,27,0,0,32,31},{25,0,11,32,0,3},{0,0,35,31,3,0}};

node* nodearr[6];

int i;

for ( i = 0 ; i < 6 ; i++ )
	nodearr[i] = NULL;


for ( i = 0 ; i < 6 ; i++ )
	if ( nodearr[i] != NULL )
		nodearr[i] = createNode(arr,i,nodearr);
	























}
