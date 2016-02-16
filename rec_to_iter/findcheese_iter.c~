#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
#include "maze.h"
#include "MazeOps.h"

void set(coord* head,coord* curr,int posi,int posj){
    printf("inside set %d %d\n",posi,posj);
    coord* temp = head;

    while ( temp->ptr != NULL )
        temp = temp->ptr;
   
    curr->x = posi;
    curr->y = posj;
    curr->ptr = NULL;
    curr->prev = temp;
    temp->ptr = curr;
    printf("exiting set\n");
}

Boolean findCheese(Maze m,int n,int posi,int posj,coord* head,int past_i,int past_j){
int flag;
int starts_with = 0;
int ends_with = 0;

	    while ( m[posi][posj] != 9 ){
	
	flag = 0;

        if ( m[posi-1][posj] != 1 && posi-1 != past_i && posi != 0){
            coord* curr = (coord*)malloc(sizeof(coord));
            set(head,curr,posi,posj);
            past_i = posi;
            past_j = posj;
            posi--;
	    flag = 1;
            }
        else if ( m[posi+1][posj] != 1 && posi+1 != past_i && posi != n-1 ){
            coord* curr = (coord*)malloc(sizeof(coord));
            set(head,curr,posi,posj);
            past_i = posi;
            past_j = posj;
            posi++;
		flag = 1;
            }
        else if ( m[posi][posj-1] != 1 && posj-1 != past_j && posj != 0){
            coord* curr = (coord*)malloc(sizeof(coord));
            set(head,curr,posi,posj);
            past_i = posi;
            past_j = posj;
            posj--;
		flag = 1;
            }
        else if ( m[posi][posj+1] != 1 && posj+1 != past_j && posj != n-1){
            coord* curr = (coord*)malloc(sizeof(coord));
            set(head,curr,posi,posj);
            past_i = posi;
            past_j = posj;
            posj++;
		flag = 1;
            }

	if ( flag == 0 ){
		posi = past_i;
		posj = past_j;
		//now i have to somehow get the past_i and past_j and transfer control to previious number's else if statements...doubly linked list is already implemented..
		
    }
   
    if ( m[posi][posj] == 9 ){
        coord* curr = (coord*)malloc(sizeof(coord));
        set(head,curr,posi,posj);
        return TRUE;       
    }
	
}

