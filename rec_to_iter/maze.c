#include<stdio.h>
#include<stdlib.h>
#define SIZE 5


#include "maze.h"
#include "MazeOps.h"

    

int main(int args,char* argv[]){

Maze m;
int n = createMaze(m,argv[3]);
printf("n is %d\n",n);


coord* c1 = (coord*)malloc(sizeof(coord));
c1->x = atoi(argv[1]);
c1->y = atoi(argv[2]);
c1->ptr = NULL;
c1->ptr = NULL;

findCheese(m,n,atoi(argv[1]),atoi(argv[2]),c1,-10,-10);

int i;
coord* temp = c1->ptr;
FILE* fp = fopen("output.txt","w");

while ( temp != NULL ) {
    fprintf(fp,"(%d,%d),",temp->x,temp->y);
    temp = temp->ptr;
}
printf("\r ");

}


