typedef struct scnode{
	int rNo;
	struct scnode *next;
}SCNODE;

typedef struct lpnode{
	int rNo;
	int mark;
}LPNODE;

void initTablesc(SCNODE *ht[]);
int hashFunction(int key);
void insertRecordsc(SCNODE *ht[],int rNo);
int searchRecordsc(SCNODE *ht[],int rNo);
void printhashtablesc(SCNODE *ht[]);
void destroyTablesc(SCNODE *ht[]);

void initTablelp(LPNODE ht[],int *n);
int insertRecordlp(LPNODE ht[],int rNo,int *n);
int searchRecordlp(LPNODE ht[],int rNo,int n);
void printhashtablelp(LPNODE ht[],int n);

void hashvisualizer();
void linearprobvisualize(int* arr, int n);
void sepchainvisualize(int* arr, int n);
void printwelcomehash();