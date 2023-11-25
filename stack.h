typedef struct nodechar{
	char data;
	struct nodechar* next;
}NODECHAR;

typedef struct{
	NODECHAR* top;
}STACKCHAR;

typedef struct nodeint{
	int data;
	struct nodeint* next;
}NODEINT;

typedef struct{
	NODEINT* top;
}STACKINT;

void create_stack(STACKCHAR* st);
void create_stackint(STACKINT* st);
void push(STACKCHAR* st, char ch);
char pop(STACKCHAR* st);
char peek(STACKCHAR* st);
void dispstack(STACKCHAR* stk);
void pushint(STACKINT* st, int ch);
char popint(STACKINT* st);
char peekint(STACKINT* st);
void dispstackint(STACKINT* stk);
void postconvvisualizer(char* input);
void postconv(char* p, char* postfix, STACKCHAR* st);
void postevalvisualizer(char* input);
void strrevstk(char* p, char* out, STACKCHAR* st);
void clean_stdin();
void strrevvisualizer(char* input);
void stackvisualizer();
void freestack(STACKCHAR* st);
void freestackint(STACKINT* st);
void printwelcome();