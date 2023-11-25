#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "tree.h"

SNODE *NewNode(NODE* data){
    SNODE *newnode = (SNODE*)malloc(sizeof(SNODE));
    newnode->next = NULL;
    newnode->data = data;
    return newnode;
}

SNODE *Push(SNODE **top, NODE* data) {
    SNODE *newnode = NewNode(data);
    if (*top) {
        newnode->next = *top;
        *top = newnode;
    } else {
        *top = newnode;
    }
    return *top;
}

NODE *Pop(SNODE **top) {
    if (*top) {
        SNODE *temp_top = *top;
        *top = (*top)->next;
        NODE *poppedNode = temp_top->data;
        free(temp_top);
        return poppedNode;
    }
    return NULL;
}

void printoutput(int* output, int ind){
    printf("\n\nOUTPUT STRING: ");
    for (int i=0; i<ind; i++){
        printf("%d ", output[i]);
    }
}

void print2DUtil(NODE* root, int space){
    if (root == NULL)
        return;
    space += COUNT;
    print2DUtil(root->right, space);
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->info);
    print2DUtil(root->left, space);
}

void initTree(TREE *pt){
    pt->root = NULL;
}

void createTree(TREE *pt, int* arr, int n){
    int choice;

    NODE *temp = malloc(sizeof(NODE));
	temp->info = arr[0];
    temp->left = temp->right = NULL;
    pt->root = temp;

    for (int i=1; i<n; i++){
        temp = malloc(sizeof(NODE));
        temp->left = temp->right = NULL;
		temp->info=arr[i];

        NODE *p = pt->root;
        NODE *q = NULL;

        while (p != NULL) {
            if (temp->info <= p->info) {
                q = p;
                p = p->left;
            } else {
                q = p;
                p = p->right;
            }
        }

        if (temp->info <= q->info)
            q->left = temp;
        else
            q->right = temp;
    }
}

void printstack(SNODE *st){
    SNODE *temp=st;
    if(temp==NULL){
        printf("\t\t\t\t\t|\t\t|\n");
        printf("\t\t\t\t\t|\t\t|\n");
        printf("\t\t\t\t\t|_______________|\n");
    }
    else{
		while(temp){
			
			printf("\t\t\t\t\t|\t\t|\n");
			printf("\t\t\t\t\t|      %d",temp->data->info);printf("\t|\n");
			printf("\t\t\t\t\t|_______________|\n");
			temp=temp->next;
		}
	}
    printf("\n\n");
}

void printpush(SNODE*st,NODE* r,int arr[],int index, char* algo){
    printwelcometree();
	printf("ALGORITHM IS: %s", algo);
    print2D(r);
    printf("\n\n\n");
    
    SNODE *temp=st;
    if(!temp){
        printf("\t\t\t\t\t|\t\t|\n");
        printf("\t\t\t\t\t|\t\t|\n");
        printf("\t\t\t\t\t|_______________|\n");
    }
    else{
    printf("PUSHED %d INTO STACK",temp->data->info);
    printoutput(arr, index);
    printf("\n\n");
    while(temp){
        
        printf("\t\t\t\t\t|\t\t|\n");
        printf("\t\t\t\t\t|      %d",temp->data->info);printf("\t|\n");
        printf("\t\t\t\t\t|_______________|\n");
        temp=temp->next;
    }}
    printf("\n\n");
}

void popprint(SNODE *st, int p,NODE *r,int arr[],int index, char* algo){
    printwelcometree();
	printf("ALGORITHM: %s", algo);
    print2D(r);
    printf("\n\n\n");
    
    printf("POPPED: %d",p);
    SNODE *temp = st;
    if (!temp) {
        printoutput(arr, index);
    printf("\n\n");
        printf("\t\t\t\t\t|\t\t|\n");
        printf("\t\t\t\t\t|\t\t|\n");
        printf("\t\t\t\t\t|_______________|\n");
    } 
    else {
        printoutput(arr, index);
        printf("\n\n");
            while (temp) {
                printf("\t\t\t\t\t|\t\t|\n");
                printf("\t\t\t\t\t|      %d", temp->data->info);printf("\t|\n");
                printf("\t\t\t\t\t|_______________|\n");
                temp = temp->next;
            }
        }
        printf("\n\n");
}

void preord(NODE *r){
    int arr[100]={0},index=0;
    int p;char dummy;
    if (r != NULL) {
		NODE * current=r;
		SNODE*st=NULL;
		st=Push(&st,current);
		printpush(st,r,arr,index,"PREORDER TRAVERSAL (ITERATIVE APPROACH)");
		printf("PRESS ENTER TO CONTINUE...\n");
		getch(); 

		while(st!=NULL){
			p=st->data->info;
			arr[index++]=p;
			current=Pop(&st);
			popprint(st,p,r,arr,index,"PREORDER TRAVERSAL (ITERATIVE APPROACH)");
			printf("PRESS ENTER TO CONTINUE...\n");
			getch();

			if(current->right!=NULL)
				st=Push(&st,current->right);

			printpush(st,r,arr,index,"PREORDER TRAVERSAL (ITERATIVE APPROACH)");
			printf("PRESS ENTER TO CONTINUE...\n");
			getch(); 

			if(current->left!=NULL)
				st=Push(&st,current->left);

			printpush(st,r,arr,index,"PREORDER TRAVERSAL (ITERATIVE APPROACH)");
			printf("PRESS ENTER TO CONTINUE...\n");
			getch();
		}
	}
    printwelcometree();
	printf("ALGORITHM: PREORDER TRAVERSAL (ITERATIVE APPROACH)");
	printoutput(arr, index);
    printf("\n\nPRESS ENTER TO EXIT...");
    getch();
}

void preorder(TREE *pt){
    preord(pt->root);
}

void treevisualizer(){
	int num;
	printwelcometree();
	printf("1.INORDER TRAVERSAL (ITERATIVE APPROACH)\n2.POSTORDER TRAVERSAL (ITERATIVE APPROACH)\n\
3.PREORDER TRAVERSAL (ITERATIVE APPROACH)\n\nINPUT: ");

	fflush(stdin);
	num=getch()-'0';

	if (num==1){
		inordvisualizer();
	}
	else if (num==2){
		postordvisualizer();
	}
	else if (num==3){
		preordvisualizer();
	}
}

void postorder(TREE *pt) {
    postord(pt->root);
}

void postord(NODE *r){
	int p;
	int output[100]={0};
	int ind=0;
    if (r != NULL) {
        SNODE *s1=NULL;
        SNODE *s2=NULL;
        s1=Push(&s1,r);
		printwelcometree();
		printf("ALGORITHM: POSTORDER TRAVERSAL (ITERATIVE APPROACH)\n\n");
        print2D(r);
        printf("\n\n");
        printf("STACK S1:\n\n");
        printstack(s1);
        printf("STACK S2:\n\n");
        printstack(s2);
        printf("\n\nPUSHED %d INTO STACK 1\n",s1->data->info);
        printf("\n\n");
        printf("PRESS ENTER TO CONTINUE...\n");
        getch();

        NODE *current;
        while(s1!=NULL){
            p=s1->data->info;
            current=Pop(&s1);
			printwelcometree();
			printf("ALGORITHM: POSTORDER TRAVERSAL (ITERATIVE APPROACH)\n\n");
            print2D(r);
            printf("\n\n");
            printf("STACK S1:\n\n");
            printstack(s1);
            printf("STACK S2:\n\n");
            printstack(s2);
            printf("\n\nPOPPED %d FROM STACK 1\n",p);
            printf("\n\n");
            printf("PRESS ENTER TO CONTINUE...\n");
            getch();

            s2=Push(&s2,current);
			printwelcometree();
			printf("ALGORITHM: POSTORDER TRAVERSAL (ITERATIVE APPROACH)\n\n");
            print2D(r);
            printf("\n\n");
            printf("STACK S1:\n\n");
            printstack(s1);
            printf("STACK S2:\n\n");
            printstack(s2);
            printf("\n\nPUSHED %d INTO STACK 2\n",s2->data->info);
            printf("\n\n");
            printf("PRESS ENTER TO CONTINUE...\n");
            getch();

            if(current->left!=NULL){
                s1=Push(&s1,current->left);
				printwelcometree();
				printf("ALGORITHM: POSTORDER TRAVERSAL (ITERATIVE APPROACH)\n\n");
                print2D(r);
                printf("\n\n");
                printf("STACK S1:\n\n");
                printstack(s1);
                printf("STACK S2:\n\n");
                printstack(s2);
                printf("\n\nPUSHED %d INTO STACK 1\n",s1->data->info);
                printf("\n\n");
                printf("PRESS ENTER TO CONTINUE...\n");
                getch();
            }
            if(current->right!=NULL){
                s1=Push(&s1,current->right);
				printwelcometree();
				printf("ALGORITHM: POSTORDER TRAVERSAL (ITERATIVE APPROACH)\n\n");
                print2D(r);
                printf("\n\n");
                printf("STACK S1:\n\n");
                printstack(s1);
                printf("STACK S2:\n\n");
                printstack(s2);
                printf("\n\nPUSHED %d INTO STACK 1\n",s1->data->info);
                printf("\n\n");
                printf("PRESS ENTER TO CONTINUE...\n");
                getch();
            }
            
        }
        while(s2!=NULL){
            p=s2->data->info;
            current=Pop(&s2);
            output[ind++]=current->info;
			printwelcometree();
			printf("ALGORITHM: POSTORDER TRAVERSAL (ITERATIVE APPROACH)\n\n");
            print2D(r);
            printf("\n\n");
            printf("STACK S1:\n\n");
            printstack(s1);
            printf("STACK S2:\n\n");
            printstack(s2);
            printf("\n\nPOPPED %d FROM STACK 1\n",p);
            printoutput(output, ind);
            printf("\n\n\n");
			printf("PRESS ENTER TO CONTINUE...\n");
            getch();
		}
	}
	printwelcometree();
	printf("ALGORITHM: POSTORDER TRAVERSAL (ITERATIVE APPROACH)");
	printoutput(output, ind);
    printf("\n\nPRESS ENTER TO EXIT...");
    getch();
}

void postordvisualizer(){
	int n=0, inp[100];

	printwelcometree();
	printf("\n\nALGORITHM: POSTORDER TRAVERSAL (ITERATIVE APPROACH)");
	printf("\n\nENTER THE NUMBER OF ELEMENTS: ");
	scanf("%d", &n);

	printf("\n\nENTER THE ELEMENTS:\n");
	for (int i=0; i<n; i++){
		scanf("%d", &inp[i]);
	}

    printwelcometree();
    printf("ALGORITHM:\n\
1.PUSH THE ROOT NODE TO STACK 2.\n\
2.PUSH THE LEFT CHILD NODE TO STACK 1 FIRST THEN PUSH RIGHT CHILD NODE TO STACK 1.\n\
3.NOW POP THE STACK 1 UNTILL ITS EMPTY AND PUSH THE POPPED ELEMENTS TO STACK 2.\n\
4.REPEAT THE STEP 2 FOR RIGHT SUBTREE FIRST AND THEN LEFT SUBTREE.\n\
5.POP ALL THE NODES FROM STACK 2 AND PRINT THE VALUE IN THE OUTPUT.\n");
    printf("\n\nPRESS ENTER TO CONTINUE...:");
    getch();

    TREE tobj;
    initTree(&tobj);
    createTree(&tobj, inp, n);
    system("cls");
	printwelcometree();
    postorder(&tobj);
}

void inorder(TREE *pt) {
    inord(pt->root);
}

void inord(NODE *r){
	int arr[100]={0},index=0;
    NODE *poppedNode;

    if (r != NULL) {
        SNODE *st = NULL;
        NODE *current = r;
        do {
            while (current != NULL) {
                st = Push(&st, current);
                printpush(st,r,arr,index,"INORDER TRAVERSAL (ITERATIVE APPROACH)");
                printf("NEXT\n");
                getch();
                current = current->left;
            }
            int p=st->data->info;
            poppedNode = Pop(&st);
            arr[index++]=p;
            popprint(st,p,r,arr,index,"INORDER TRAVERSAL (ITERATIVE APPROACH)");
            printf("PRESS ENTER TO CONTINUE...\n");
            getch(); 
            if (poppedNode != NULL) {
                current = poppedNode->right;
            }
        } while (st != NULL || current != NULL);
	}
	printwelcometree();
	printf("ALGORITHM: INORDER TRAVERSAL (ITERATIVE APPROACH)");
	printoutput(arr, index);
    printf("\n\nPRESS ENTER TO EXIT...");
    getch();
}

void inordvisualizer(){
	int n=0, inp[100];

	printwelcometree();
	printf("\n\nALGORITHM: INORDER TRAVERSAL (ITERATIVE APPROACH)");
	printf("\n\nENTER THE NUMBER OF ELEMENTS:");
	scanf("%d", &n);

	printf("\n\nENTER THE ELEMENTS:\n");

	for (int i=0; i<n; i++){
		scanf("%d", &inp[i]);
	}

    printwelcometree();
    printf("ALGORITHM:\n\
1.PUSH THE ROOT NODE POINTER TO STACK.\n\
2.PUSH THE LEFT CHILD NODE TO STACK UNTILL THE LEFT CHILD IS NULL.\n\
3.POP THE NODE FROM THE STACK AND APPEND TO OUTPUT AND PUSH THE FIRST RIGHT CHILD\
ENCOUNTERED IN STACK\n\
4.REPEAT STEP 2 FOR RIGHT CHILD.\n\
5.POP ROOT NODE FROM THE STACK AND APPEND TO THE OUTPUT\n\
6.REPEAT FROM THE STEP 2 FOR RIGHT SUBTREE OF ROOT.\n");
    printf("\n\nPRESS ENTER TO CONTINUE...:");
    getch();

    TREE tobj;
    initTree(&tobj);
    createTree(&tobj, inp, n);
    system("cls");
	printwelcometree();
    inorder(&tobj);
}

void preordvisualizer(){
	int n=0, inp[100];

	printwelcometree();
	printf("\n\nALGORITHM: PREORDER TRAVERSAL (ITERATIVE APPROACH)");
	printf("\n\nENTER THE NUMBER OF ELEMENTS: ");
	scanf("%d", &n);

	printf("\n\nENTER THE NUMBER OF ELEMENTS: \n");
	for (int i=0; i<n; i++){
		scanf("%d", &inp[i]);
	}

    printwelcometree();
    printf("ALGORITHM:\n\
1.PRINT THE ROOT NODE VALUE IN OUTPUT.\n\
2.PUSH THE RIGHT CHILD NODE TO STACK FIRST THEN PUSH LEFT CHILD NODE.\n\
3.POP THE NODE FROM THE STACK AND PRINT TO OUTPUT TRAVERSE THE LEFT SUBTREE AND REPEAT \
STEP 2 FOR EACH NODE TRAVERSED.\n\
4.REPEAT STEP 3 FOR RIGHT SUBTREE OF EACH NODE TRAVERSED.\n");
    printf("\n\nPRESS ENTER TO CONTINUE...:");
    getch();

    TREE tobj;
    initTree(&tobj);
    createTree(&tobj, inp, n);
    system("cls");
	printwelcometree();
    preorder(&tobj);
}

void print2D(NODE * root){
    printf("\n\nTHE TREE :\n\n");
    print2DUtil(root, 0);
}

void printwelcometree(){
	system("cls");
    printf("---------------------------------------------------********  (\\_/)                        (\\_/)  ********\
---------------------------------------------------\n");
	printf("\t\t\t\t\t\t\t\
     (^.^)    TREES VISUALISER    (^.^)\n");
	printf("---------------------------------------------------********  /> <\\                        /> <\\  ********\
---------------------------------------------------");
printf("\n\n\n");
}