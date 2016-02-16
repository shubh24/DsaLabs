#include<stdio.h>
#include<stdlib.h>
#include "tree.h"

int main(int argc,char* argv[]){

FILE* fp = fopen(argv[1],"r");
int i = 0;
int l;

node* head;
head = (node*)malloc(sizeof(node));
head->succ = NULL;
fscanf(fp,"%d\n",&head->value);
head->left = NULL;
head->right = NULL;

int num = 0;

while(!feof(fp)){

	node* temp;
	temp = (node*)malloc(sizeof(node));
	temp->left = NULL;
	temp->right = NULL;
	fscanf(fp,"%d\n",&temp->value);
	

	node* search = head;
	node* prev;
	while ( search != NULL){
		
		prev = search;
		if ( temp->value < search->value ){
			search = search->left;
			l = 1;
		}
		else if ( temp->value > search->value ){
			search = search->right;
			l = 0;
		}
		
	}
	
	if ( l == 1 ) 
		prev->left = temp;
	else if ( l == 0 )
		prev->right = temp;
	temp->succ = prev;

	printf("%d\t%d\n",temp->value,temp->succ->value);



}


return 0;
}

	
	
