#include <stdio.h>

#define SIZE 5
#include "maze.h"
#include "MazeOps.h"

int createMaze(Maze m,char mazefilename[32]){
printf("inside createmaze\n");
    FILE* fp = fopen(mazefilename,"r");

    int i,j;
   
    for ( i = 0 ; i < SIZE ; i++ ){
         for ( j = 0 ; j < SIZE ; j++){
            fscanf(fp,"%d",&m[i][j]);
        }
    }
	
    fclose(fp);
	printf("exiting createmaze\n");
    return i;

}
