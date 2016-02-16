#include<stdio.h>
#include<limits.h>
#include<ctype.h>
#include<stdlib.h>

typedef struct index_list{
int index;
struct index_list* ptr_index;
}index_list;

typedef struct node{
char s;
index_list* ind;
int count;
int delim;
char yolo[20];
struct node* ptr[26];
}node;

void dfs_begin(node* head[]);

void dfs(node* head_node,char bitch[]);

int main(){


FILE* fp = fopen("yolo.txt","r");
char arr[1000000];
int i = 0;
char c;
int max_size;

while(!feof(fp)){
	
	c = fgetc(fp);
	if(isalpha(c) || c == ' ' ){
		arr[i++] = c;	
	}
	if ( c == '\n' )
		arr[i++] = ' '; 

}

max_size = i;

int index_g = 1;

node* head[26];
int k;
for( k = 0 ; k < 26 ; k++ )
	head[k] = NULL;

for ( i = 0 ; i < max_size ; i++ ) {
	
	char word[20];
	int j = 0;
		
	while ( arr[i] != ' ' && arr[i] != '\n' && i < max_size){
		word[j++] = tolower(arr[i++]);		
	}
	
	word[j] = '\0';	
	//printf("%s\n",word);

	int x;	
	j = 0;
	c = word[j++];

	node* temp = NULL;
	
	if ( head[c - 'a'] == NULL ){
		node* new = (node*)malloc(sizeof(node));
		new->s = c;
		new->ind = NULL;
		new->count = 0;
		new->delim = 0;
		new->yolo[0] = '\0';
		head[c-'a'] = new;
		temp = new;
	}
	
	else{	
		temp = head[c-'a'];
	}
	
	c = word[j++];

	while( c != '\0' ){
	  if ( temp->ptr[c-'a'] == NULL){
		node* new = (node*)malloc(sizeof(node));
		new->s = c;
		new->ind = NULL;
		new->count = 0;
		new->yolo[0] = '\0';
		new->delim = 0;
		for( k = 0 ; k < 26 ; k++ )
			new->ptr[k] = NULL;
		temp->ptr[c-'a'] = new;
		temp = new;
		}
	else 
		temp = temp->ptr[c-'a'];

		c = word[j++];
	}
	
	temp->ind = insertIndex(index_g);
	temp->count++;
	temp->delim = 1;	
	
		

	//printf("%d\n",temp->count);
	//printf("%d\n",temp->index);
}	

dfs_begin(head);
}


void dfs_begin(node* head[]){

	int i;
	char hi[1];
	hi[0] = '\0';

	for ( i = 0 ; i < 26 ; i++ ){
		if ( head[i] != NULL )
			dfs(head[i],hi);
	}
}

void dfs(node* head_node,char bitch[]){

	int j = 0;
	while(bitch[j] != '\0'){
		head_node->yolo[j] = bitch[j];
		j++;
	}
	
	head_node->yolo[j++] = head_node->s;
	head_node->yolo[j] = '\0';	 
	
	
	int i;

	if(head_node->delim == 1){
		printf("%s\t%d\t%d\n",head_node->yolo,head_node->index,head_node->count);
	}

	for ( i = 0 ; i < 26 ;i++ ){
		if ( head_node->ptr[i] != NULL )
			dfs(head_node->ptr[i],head_node->yolo);
	}























}




