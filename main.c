#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "hash.h"
#include "tree.h"

int main(){
    system("cls");
    printf("---------------------------------------------------********  (\\_/)                        (\\_/)  ********\
---------------------------------------------------\n");
	printf("\t\t\t\t\t\t\t\
     (^.^)    VISUALISE YOUR DS   (^.^)\n");
	printf("---------------------------------------------------********  /> <\\                        /> <\\  ********\
---------------------------------------------------");
printf("\n\n\n");
    printf("1.VISUALISE STACK APPLICATIONS\n");
    printf("2.VISUALISE TREE APPLICATIONS\n");
    printf("3.VISUALISE HASH FUNCTIONS\n\n\n");
    printf("WHAT WOULD YOU LIKE TO VISUALISE? ");
    int num;
    scanf("%d", &num);

    if (num==1){
        stackvisualizer();
    }
    else if (num==2){
        treevisualizer();
    }
    else if (num==3){
        hashvisualizer();
    }

    return 0;
}