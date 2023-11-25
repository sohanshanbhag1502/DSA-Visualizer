#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <conio.h>
#include "hash.h"
#define SIZE 7

void initTablesc(SCNODE *ht[]){
	for(int i=0;i<SIZE;i++)
		ht[i]=NULL;
}

int hashFunction(int key){
	return key%SIZE;
}

void insertRecordsc(SCNODE *ht[],int rNo){
	int index=hashFunction(rNo);
	
	SCNODE *newSCNODE=malloc(sizeof(SCNODE));
	newSCNODE->rNo=rNo;
	newSCNODE->next=ht[index];
	ht[index]=newSCNODE;
}

int searchRecordsc(SCNODE *ht[],int rNo){
	int index=hashFunction(rNo);
	
	SCNODE *p=ht[index];
	
	while(p!=NULL)
	{
		if(p->rNo==rNo)
		{
			return 1;
		}
		p=p->next;
	}
	return 0;
}

void printhashtablesc(SCNODE *ht[]){
	SCNODE *p;
	for(int i=0;i<SIZE;i++)
	{
		p=ht[i];
		printf("|    %d    | ---> ", i);
		
		while(p!=NULL)
		{
			printf("|    %d    | ---> ", p->rNo);
			p=p->next;
		}
		printf("|   NULL  |\n");
	}
}

void destroyTablesc(SCNODE *ht[]){
	SCNODE *p,*q;
	
	for(int i=0;i<SIZE;i++)
	{
		p=ht[i];
		while(p!=NULL)
		{
			q=p->next;
			free(p);
			p=q;
		}
		ht[i]=NULL;
	}
}

void printwelcomehash(){
    system("cls");
    printf("---------------------------------------------------********  (\\_/)                        (\\_/)  ********\
---------------------------------------------------\n");
	printf("\t\t\t\t\t\t\t\
     (^.^) HASH TABLE VISUALISER  (^.^)\n");
	printf("---------------------------------------------------********  /> <\\                        /> <\\  ********\
---------------------------------------------------");
printf("\n\n\n");
}

void initTablelp(LPNODE ht[],int *n){
	for(int i=0;i<SIZE;i++){
		ht[i].rNo=-1;
		ht[i].mark=-1;
	}
	*n=0;
}

int insertRecordlp(LPNODE ht[],int rNo,int *n){
	int index=rNo%SIZE;
	while(ht[index].mark!=-1){
		index=(index+1)%SIZE;
	}
	ht[index].rNo=rNo;
	ht[index].mark=1;
	(*n)++;
	return index;
}

int searchRecordlp(LPNODE ht[],int rNo,int n){
	if(n==0)
		return 0;
	int index=rNo%SIZE;
	int count=0;
	while(count<n && ht[index].rNo!=rNo){
		if(ht[index].mark==1)
			count++;
		index=(index+1)%SIZE;
	}
	if(ht[index].rNo==rNo && ht[index].mark==1){
		return 1;
	}
	return 0;
}

void printhashtablelp(LPNODE ht[],int n){
	printf("VALUES: ");
	for(int i=0;i<SIZE;i++){
		if (i==0)
			printf("|    %d    |",ht[i].rNo);
		else
			printf("    %d    |",ht[i].rNo);
	}
	printf("\n");
	printf("MARK:   ");
	for(int i=0;i<SIZE;i++){
		if (i==0)
			printf("|    %d    |",ht[i].mark);
		else
			printf("    %d    |",ht[i].mark);
	}
}


void linearprobvisualize(int* arr, int n){
	LPNODE ht[SIZE];
	int size;

	initTablelp(ht, &size);

	printwelcomehash();
	printf("ALGORITHM:\n\
1.CALCULATE THE HASH VALUE FOR GIVEN INPUT USING THE FORMULA x%%N WHERE x IS THE INPUT AND\
N IS THE ARRAY SIZE.\n\
2.CHECK IF THE ARRAY ELEMENT AT INDEX HASH VALUE IS USED OR NOT.\n\
3.IF ELEMENT IS USED THEN INCREMENT THE VALUE OF INDEX BY 1 UNTILL A UNUSED ELEMENT IS FOUND.\n\
4.INSERT THE ELEMENT AT THAT PARTICULAR INDEX.\n\
5.LINK THE HASHVALUE INDEX OF HASH TABLE ARRAY TO NODE AND NEXT POINTER OF NODE TO THE ARRAY \
ELEMENT'S CURRENT VALUE.");
	printf("\n\nPRESS ANY KEY TO CONTINUE:");
	getch();

	for (int i=0; i<n; i++){
		int k=0;
		k=insertRecordlp(ht, arr[i], &size)-hashFunction(arr[i]);
		printwelcomehash();
		printf("ALGORITHM: LINEAR PROBING INSERTION");
		printf("\n\nHASH TABLE:\n\n");
		printhashtablelp(ht, size);
		printf("\n\nELEMENT INSERTED: %d", arr[i]);
		printf("\n\nHASH VALUE: %d", hashFunction(arr[i]));
		printf("\n\nVALUE OF k:%d", k);
		if (i!=n-1)
			printf("\n\nPRESS ENTER TO CONTINUE...");
		else
			printf("\n\nPRESS ENTER TO EXIT");
		getch();
	}
}

void sepchainvisualize(int* arr, int n){
	SCNODE* ht[n];
	initTablesc(ht);

	printwelcomehash();
	printf("ALGORITHM:\n\
1.CALCULATE THE HASH VALUE FOR GIVEN INPUT USING THE FORMULA x%%N WHERE x IS THE INPUT AND\
N IS THE ARRAY SIZE.\n\
2.CREATE A NEW NODE FOR THE GIVEN VALUE.\n\
3.LINK THE HASHVALUE INDEX OF HASH TABLE ARRAY TO NODE AND NEXT POINTER OF NODE TO THE ARRAY \
ELEMENT'S CURRENT VALUE.");
	printf("\n\nPRESS ANY KEY TO CONTINUE:");
	getch();

	for (int i=0; i<n; i++){
		insertRecordsc(ht, arr[i]);
		printwelcomehash();
		printf("ALGORITHM: SEPERATE CHAINING INSERTION");
		printf("\n\nHASH TABLE:\n\n");
		printhashtablesc(ht);
		printf("\n\nELEMENT INSERTED: %d", arr[i]);
		printf("\n\nHASH VALUE: %d", hashFunction(arr[i]));
		if (i!=n-1)
			printf("\n\nPRESS ENTER TO CONTINUE...");
		else
			printf("\n\nPRESS ENTER TO EXIT");
		getch();
	}
	destroyTablesc(ht);
}

void hashvisualizer(){
	int inp;
	printwelcomehash();
	printf("1.VISUALISE LINEAR PROBING\n2.VISUALISE SEPERATE CHAINING\n\n\n");
	printf("INPUT:");
	inp=getch()-'0';

	printwelcomehash();
	if (inp==1){
		printf("ALGORITHM: LINEAR PROBING");
	}
	else if (inp==2){
		printf("ALGORITHM: SEPERATE CHAINING");
	}

	int n;
	printf("\n\nENTER THE NUMBER OF INPUTS\n");
	scanf("%d", &n);

	int temparr[n];

	printf("\n\nENTER THE INPUTS:\n");
	for (int i=0; i<n; i++){
		scanf("%d",&temparr[i]);
	}

	if (inp==1){
		linearprobvisualize(temparr, n);
	}
	else if (inp==2){
		sepchainvisualize(temparr, n);
	}
}