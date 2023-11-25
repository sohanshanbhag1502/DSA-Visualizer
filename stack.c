#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "stack.h"

void create_stack(STACKCHAR* st){
	st->top=NULL;
}

void create_stackint(STACKINT* st){
	st->top=NULL;
}

void push(STACKCHAR* st, char ch){
	NODECHAR* temp=(NODECHAR*) malloc(sizeof(NODECHAR));
	temp->data=ch;
	temp->next=st->top;
	st->top=temp;
}

char pop(STACKCHAR* st){
	char tempch;
	NODECHAR* temp;
	tempch=st->top->data;
	temp=st->top->next;
	free(st->top);
	st->top=temp;
	return tempch;
}

char peek(STACKCHAR* st){
	char tempch;
    if (st->top)
	    tempch=st->top->data;
    else
        tempch=0;
	return tempch;
}


void pushint(STACKINT* st, int ch){
	NODEINT* temp=(NODEINT*) malloc(sizeof(NODEINT));
	temp->data=ch;
	temp->next=st->top;
	st->top=temp;
}

char popint(STACKINT* st){
	char tempch;
	NODEINT* temp;
	tempch=st->top->data;
	temp=st->top->next;
	free(st->top);
	st->top=temp;
	return tempch;
}

char peekint(STACKINT* st){
	char tempch;
    if (st->top)
        tempch=st->top->data;
    else
        tempch=0;
	return tempch;
}

void printwelcome(){
    system("cls");
    printf("---------------------------------------------------********  (\\_/)                        (\\_/)  ********\
---------------------------------------------------\n");
	printf("\t\t\t\t\t\t\t\
     (^.^)    STACK VISUALISER    (^.^)\n");
	printf("---------------------------------------------------********  /> <\\                        /> <\\  ********\
---------------------------------------------------");
printf("\n\n\n");
}

void clean_stdin(){
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

void stackvisualizer(){
    int inp;
    printwelcome();
    printf("1.VISUALISE INFIX TO POSTFIX\n");
    printf("2.VISUALISE POSTFIX EVAL\n");
    printf("3.VISUALISE STRING REVERSAL\n");
    printf("\nINPUT:");
    scanf("%d", &inp);

    printf("\n\nINPUT FOR VISUALISER ALGORITHM: ");
    if (inp==1){
        char inp[20];
        scanf("%s", inp);
        postconvvisualizer(inp);
    }
    else if (inp==2){
        char inp[20];
        scanf("%s", inp);
        postevalvisualizer(inp);
    }
    else if (inp==3){
        char inp[100]={0};
        clean_stdin();
        fgets(inp, 100, stdin);
        strrevvisualizer(inp);
    }

}

void postconv(char* p, char* postfix, STACKCHAR* st){
	static int i=0;
	if ('0'<=*p && *p<='9'){
        postfix[i++]=*p;
        printwelcome();
        printf("ALGORITHM: INFIX TO POSTFIX");
        dispstack(st);
        printf("\n\n\nOUTPUT STRING: %s", postfix);
        printf("\n\n\nOPERATION PERFORMED:APPEND %c TO OUTPUT", *p);
        printf("\n\n\n\nPRESS ENTER TO CONTINUE");
        getch();
    }
    else if (*p=='('){
        push(st, *p);
        printwelcome();
        printf("ALGORITHM: INFIX TO POSTFIX");
        dispstack(st);
        printf("\n\n\nOUTPUT STRING: %s", postfix);
        printf("\n\n\nOPERATION PERFORMED: PUSH %c TO STACK", *p);
        printf("\n\n\n\nPRESS ENTER TO CONTINUE");
        getch();
    }
    else if(*p=='+' || *p=='-' || *p=='*' || *p=='/' || *p=='%'){
        if (*p=='+' || *p=='-'){
            char tempch=peek(st);
            while (tempch=='+' || tempch=='-' || tempch=='*'
            || tempch=='/' || tempch=='%'){
                postfix[i++]=pop(st);
                tempch=peek(st);
                printwelcome();
                printf("ALGORITHM: INFIX TO POSTFIX");
                dispstack(st);
                printf("\n\n\nOUTPUT STRING: %s", postfix);
                printf("\n\n\nOPERATION PERFORMED:POPPED %c FROM STACK AND APPENDED TO OUTPUT", postfix[i-1]);
                printf("\n\n\n\nPRESS ENTER TO CONTINUE");
                getch();
            }
        }
        else if (*p=='*' || *p=='/' || *p=='%'){
            char tempch=peek(st);
            while (tempch=='*' || tempch=='/' || tempch=='%'){
                postfix[i++]=pop(st);
                tempch=peek(st);
                printwelcome();
                printf("ALGORITHM: INFIX TO POSTFIX");
                dispstack(st);
                printf("\n\n\nOUTPUT STRING: %s", postfix);
                printf("\n\n\nOPERATION PERFORMED:POPPED %c FROM STACK AND APPENDED TO OUTPUT", postfix[i-1]);
                printf("\n\n\n\nPRESS ENTER TO CONTINUE");
                getch();
            }
        }
        push(st, *p);
        printwelcome();
        printf("ALGORITHM: INFIX TO POSTFIX");
        dispstack(st);
        printf("\n\n\nOUTPUT STRING: %s", postfix);
        printf("\n\n\nOPERATION PERFORMED: PUSH %c TO STACK", *p);
        printf("\n\n\n\nPRESS ENTER TO CONTINUE");
        getch();
    }
    else if (*p==')'){
        char tempch=pop(st);
        while (tempch!='('){
            postfix[i++]=tempch;
            tempch=pop(st);
            printwelcome();
            printf("ALGORITHM: INFIX TO POSTFIX");
            dispstack(st);
            printf("\n\n\nOUTPUT STRING: %s", postfix);
            printf("\n\n\nOPERATION PERFORMED:POPPED %c FROM STACK AND APPENDED TO OUTPUT", postfix[i-1]);
            printf("\n\n\n\nPRESS ENTER TO CONTINUE");
            getch();
        }
    }
	postfix[i]='\0';
}

void postconvvisualizer(char* input){
	char postfix[50]={0};
	char* p=input;

    STACKCHAR st;
    create_stack(&st);

    int len=strlen(input);

    printwelcome();
    printf("ALGORITHM:\n1.TRAVERSE THOUGH THE EXPRESSION\n\
2.IF x IS A NUMBER APPEND TO OUTPUT STRING.\n\
3.IF x IS A OPERATOR POP FROM THE STACK UNTILL THE STACK TOP IS A OPERATOR THAT HAS A\
PRECEDENCE HIGHER THAN x THEN PUSH x TO THE STACK.\n\
4.IF x IS LEFT PARENTHESIS THEN PUSH IT TO THE STACK.\n\
5.IF x IS RIGHT PARENTHESIS THEN POP ALL OPERATORS FROM THE STACK UNTILL THE STACK TOP IS LEFT PARENTHESIS.\n\
5.WHEN YOU REACH THE END OF EXPRESSION POP ALL OPERATORS FROM THE STACK AND APPEND IT TO\
THE OUTPUT.");
    printf("\n\nPRESS ENTER TO CONTINUE:");
    getch();
    while (*p){
        postconv(p, postfix, &st);
        p++;
    }
    while (peek(&st)){
        int len=strlen(postfix);
        postfix[len]=pop(&st);
        postfix[len+1]=0;
        printwelcome();
        printf("ALGORITHM: INFIX TO POSTFIX");
        dispstack(&st);
        printf("\n\n\nOUTPUT STRING: %s", postfix);
        printf("\n\n\nOPERATION PERFORMED:POPPED %c FROM STACK AND APPENDED TO OUTPUT", 
        postfix[len]);
        printf("\n\n\n\nPRESS ENTER TO CONTINUE");
        getch();
    }
    printwelcome();
    printf("ALGORITHM: INFIX TO POSTFIX");
    printf("\n\nINPUT INFIX EXPRESSION: %s", input);
    printf("\n\nOUTPUT POSTFIX EXPRESSION: %s", postfix);
    printf("\n\n\nPRESS ENTER TO EXIT");
    getch();
}

void postfixeval(char* p, STACKINT* st){
    int ans=0;
    if ('0'<=*p && *p<='9'){
        pushint(st, (*p-48));
        printwelcome();
        printf("ALGORITHM: POSTFIX EVALUATION");
        dispstackint(st);
        if (peekint(st))
            printf("\n\nSTACK TOP: %d", peekint(st));
        else
            printf("\n\nSTACK TOP: NULL");
        printf("\n\nCURRENT ELEMENT: %c", *p);
        printf("\n\n");
        printf("\n\n\nOPERATION PERFORMED: PUSH TO STACK");
        printf("\n\n\n\nPRESS ENTER TO CONTINUE");
        getch();
    }
    else{
        int temp1, temp2;
        char op[15]={0};
        temp2=popint(st);
        printwelcome();
        printf("ALGORITHM: POSTFIX EVALUATION");
        dispstackint(st);
        if (peekint(st))
            printf("\n\nSTACK TOP: %d", peekint(st));
        else
            printf("\n\nSTACK TOP: NULL");
        printf("\n\nCURRENT ELEMENT: %c", *p);
        printf("\n\n\nOPERATION PERFORMEND: POP FROM STACK");
        printf("\n\n\n\nPRESS ENTER TO CONTINUE");
        getch();

        temp1=popint(st);
        printwelcome();
        printf("ALGORITHM: POSTFIX EVALUATION");
        dispstackint(st);
        if (peekint(st))
            printf("\n\nSTACK TOP: %d", peekint(st));
        else
            printf("\n\nSTACK TOP: NULL");
        printf("\n\nCURRENT ELEMENT: %c", *p);
        printf("\n\n\nOOPERATION PERFORMEND: POP FROM STACK");
        printf("\n\n\n\nPRESS ENTER TO CONTINUE");
        getch();

        switch(*p){
            case '+':{
                ans=temp1+temp2;
                strcpy(op, "Sum");
                break;
            }
            case '-':{
                ans=temp1-temp2;
                strcpy(op, "Difference");
                break;
            }
            case '*':{
                ans=temp1*temp2;
                strcpy(op, "Product");
                break;
            }
            case '/':{
                ans=temp1/temp2;
                strcpy(op, "Quotient");
                break;
            }
            case '%':{
                ans=temp1%temp2;
                strcpy(op, "Remainder");
                break;
            }
        }
        pushint(st, ans);
        printwelcome();
        printf("ALGORITHM: POSTFIX EVALUATION");
        dispstackint(st);
        if (peekint(st))
            printf("\n\nSTACK TOP: %d", peekint(st));
        else
            printf("\n\nSTACK TOP: NULL");
        printf("\n\nCURRENT ELEMENT: %c", *p);
        printf("\n\n\nOPERATION PERFORMED: COMPUTE THE %s AND PUSH TO STACK", op);
        printf("\n\n\n\nPRESS ENTER TO CONTINUE");
        getch();
	}
}

void postevalvisualizer(char* input){
	char *p=&input[0];

	STACKINT st;
	create_stackint(&st);

    printwelcome();
    printf("ALGORITHM:\n1.TRAVERSE THOUGH THE EXPRESSION\n\
2.IF x IS A NUMBER PUSH IT TO STACK.\n\
3.IF x IS A OPERATOR POP TWO NUMBERS FROM THE STACK AND PERFORM THE OPERATION, THEN PUSH THE RESULT TO STACK.\n\
4.IF x IS A \n\
5.IF x IS RIGHT PARENTHESIS THEN POP ALL OPERATORS FROM THE STACK UNTILL THE STACK TOP IS LEFT PARENTHESIS.\n\
5.WHEN YOU REACH THE END OF EXPRESSION POP ALL OPERATORS FROM THE STACK AND APPEND IT TO\
THE OUTPUT.");
    printf("\n\nPRESS ENTER TO CONTINUE:");
    getch();
    while (*p){
        postfixeval(p, &st);
        p++;
    }
    printwelcome();
    printf("ALGORITHM: STACK REVERSAL");
    printf("\n\nINPUT: %s", input);
    printf("\n\nFINAL RESULT OF EXPRESSION: %d", popint(&st));
    printf("\n\n\n\nPRESS ENTER TO EXIT");
}

void strrevstk(char* p, char* out, STACKCHAR* st){
    static int i=0;
    if (*p){
        push(st, *p);
        printwelcome();
        printf("ALGORITHM: STACK REVERSAL");
        dispstack(st);
        if (peek(st))
            printf("\n\nSTACK TOP: %c", peek(st));
        else
            printf("\n\nSTACK TOP: NULL");
        printf("\n\nCURRENT ELEMENT: %c", *p);
        printf("\n\n\nOPERATION PERFORMEND: PUSH TO STACK");
        printf("\n\n\n\nPRESS ENTER TO CONTINUE");
        getch();
    }
    else{
        out[i++]=pop(st);
        printwelcome();
        printf("ALGORITHM: STACK REVERSAL");
        dispstack(st);
        if (peek(st))
            printf("\n\nSTACK TOP: %c", peek(st));
        else
            printf("\n\nSTACK TOP: NULL");
        printf("\n\nOUTPUT STRING: %s", out);
        printf("\n\n\nOPERATION PERFORMEND: POP FROM STACK");
        printf("\n\n\n\nPRESS ENTER TO CONTINUE");
        getch();
    }
    out[i]=0;
}

void strrevvisualizer(char* input){
    char *p=&input[0];
    char output[100]={0};

    STACKCHAR stk;
    create_stack(&stk);

    printwelcome();
    printf("ALGORITHM:\n\
1. PUSH ALL CHARACTERS TO STACK\n\
2. WHEN REACHED END OF STRING POP ALL CHARACTERS FROM STACK AND APPEND IT TO OUTPUT.");
    printf("\n\nPRESS ENTER TO CONTINUE:");
    getch();
    while (*p){
        strrevstk(p, output, &stk);
        p++;
    }
    while (peek(&stk)){
        strrevstk(p, output, &stk);
    }
    printwelcome();
    printf("ALGORITHM: STACK REVERSAL");
    printf("\n\nINPUT STRING: %s", input);
    printf("\n\nOUTPUT STRING:%s", output);
    printf("\n\nPRESS ENTER TO CONTINUE");
    getch();
}

void dispstack(STACKCHAR* stk){
    for (int i=0; i<15; i++){
        printf(" ");
    }
    printf("\n\nSTACK:\n\n");
    NODECHAR* nd=stk->top;
    if (nd){
        while (nd!=NULL){
            for (int i=0; i<15; i++){
                printf(" ");
            }
            printf("|         |\n");
            for (int i=0; i<15; i++){
                printf(" ");
            }
            printf("|    %c    |\n", nd->data);
            for (int i=0; i<15; i++){
                printf(" ");
            }
            printf("|_________|\n");
            nd=nd->next;
        }
    }
    else{
        printf("EMPTY STACK!");
    }
}

void dispstackint(STACKINT* stk){
    for (int i=0; i<15; i++){
        printf(" ");
    }
    printf("\n\nSTACK:\n\n");
    NODEINT* nd=stk->top;
    if (nd){
        while (nd!=NULL){
            char num[3]={0};
            sprintf(num, "%d", nd->data);
            for (int i=0; i<15; i++){
                printf(" ");
            }
            printf("|         |\n");
            for (int i=0; i<15; i++){
                printf(" ");
            }
            printf("|   %2s    |\n", num);
            for (int i=0; i<15; i++){
                printf(" ");
            }
            printf("|_________|\n");
            nd=nd->next;
        }
    }
    else{
        printf("EMPTY STACK!");
    }
}

void freestack(STACKCHAR* st){
	if(st->top){
		NODECHAR* temp=st->top->next;
		if (st->top){
			while (st->top!=NULL){
				temp=st->top->next;
				free(st->top);
				st->top=temp;
			}
			st->top=NULL;
		}
	}
}

void freestackint(STACKINT* st){
	if(st->top){
		NODEINT* temp=st->top->next;
		if (st->top){
			while (st->top!=NULL){
				temp=st->top->next;
				free(st->top);
				st->top=temp;
			}
			st->top=NULL;
		}
	}
}