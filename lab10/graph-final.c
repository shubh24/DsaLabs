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

for ( i = 0 ; i < 6 ; i++ ){
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

int bfs(list list_b[],int posn,int arr[],int money){


int i = posn;
int stack[5] = {-1,-1,-1,-1,-1};
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
	if (money == 0)
		return 0;

	for ( i = 0 ; i < 5 ; i++ ){
		if ( stack[i] != -1){
			int x = bfs(list_b,stack[i],arr,money);
			money -= list_b[stack[i]].next->length; 
		}
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
	
	if ( arr[temp->num] != 1 ){
		money += temp->length;
		money += dfs(list_b,temp->num,arr);
	}
	
	temp = temp->ptr;
}
int i;




return money;
}

int main(){


list list_b[6];
initialize(list_b);

addEdge(0,1,1,list_b);
addEdge(0,4,1,list_b);
addEdge(0,3,1,list_b);

addEdge(1,0,1,list_b);
addEdge(1,3,1,list_b);

addEdge(2,5,1,list_b);



addEdge(3,0,1,list_b);
addEdge(3,1,1,list_b);

addEdge(4,0,1,list_b);

addEdge(5,2,1,list_b);

int arr[6] = {0,0,0,0,0,0};
int i;
printf("\nBFS\n");

int z = bfs(list_b,3,arr,2);

if ( z == 1 )
for ( i = 0 ; i < 6 ; i++ ){
	if ( arr[i] == 0 )
		bfs(list_b,i,arr,2);
}

int arr1[6] = {0,0,0,0,0,0};
printf("\nDFS\n");

int money = 0;
/*for ( i = 0 ; i < 6 ; i++ ){
	if ( arr1[i] == 0 )
		money += dfs(list_b,i,arr1);
}*/
money = dfs(list_b,0,arr1);
printf("Money is %d\n",money);

}
