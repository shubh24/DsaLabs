#include<stdio.h>
#include<stdlib.h>

typedef struct node{
int num;
int length;
struct node* ptr;
}node;

typedef struct list{
int n;
node* next;
}list;

void initialize(list list_b[]){
int i;

for ( i = 0 ; i < 5 ; i++ ){
	list_b[i].n = i;
	list_b[i].next = NULL;
}


}

void addEdge(int s,int e,int w,list list_b[]){
	

node* temp = list_b[s].next;
node* prev = NULL;

while ( temp != NULL ){
	prev = temp;
	temp = temp->ptr;
}

	node* n1 = (node*)malloc(sizeof(node));
	n1->num = e;
	n1->length = w;
	n1->ptr = NULL;
	
if ( prev == NULL ){
	
	list_b[s].next = n1;
}

else{
	prev->ptr = n1;
}


}

void bfs(list list_b[],int posn,int arr[],int money){


int i = posn;
int stack[4] = {-1,-1,-1,-1};
int j = 0;
	
	if ( arr[i] != 1 ){
		printf("%d\n",list_b[i].n);
		arr[i] = 1;
	}
	

	node* temp = list_b[i].next;

	while ( temp != NULL ){
		
		if ( arr[temp->num] != 1 ){
			if (money-temp->length >= 0){
				printf("%d\t%d\n",temp->num,temp->length);
				arr[temp->num] = 1;
				stack[j++] = temp->num;
				money-=temp->length;
			}
		}
		
		temp = temp->ptr;
	
	}

	for ( i = 0 ; i < 4 ; i++ ){
		if ( stack[i] != -1)
			bfs(list_b,stack[i],arr,money);
	}


}

int dfs(list list_b[],int posn,int arr[]){

int money = 0;

	if ( arr[posn] != 1 ){
		printf("%d\n",list_b[posn].n);
		arr[posn] = 1;
	}


node* temp = list_b[posn].next;

while ( temp != NULL ){
	
	if ( arr[temp->num] != 1 )
		money += dfs(list_b,temp->num,arr);

}

return money;




























}

int main(){


list list_b[5];
initialize(list_b);

addEdge(0,1,17,list_b);
addEdge(0,2,28,list_b);
addEdge(0,4,25,list_b);

addEdge(1,0,17,list_b);
addEdge(1,2,30,list_b);
addEdge(1,3,27,list_b);

addEdge(2,0,28,list_b);
addEdge(2,1,30,list_b);
addEdge(2,4,11,list_b);

addEdge(3,1,27,list_b);

addEdge(4,0,25,list_b);
addEdge(4,2,30,list_b);

int arr[5] = {0,0,0,0,0};

bfs(list_b,2,arr,70);

int arr1[5] = {0,0,0,0,0};

printf("DFS cost is %d\n",dfs(list_b,0,arr1));

}
