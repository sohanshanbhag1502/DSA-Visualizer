#define COUNT 10

typedef struct node {
    int info;
    struct node *left;
    struct node *right;
} NODE;

typedef struct tree {
    struct node *root;
} TREE;

typedef struct nodee {
    NODE* data;
    struct nodee *next;
} SNODE;

SNODE *NewNode(NODE* item);
SNODE *Push(SNODE **top, NODE* data);
NODE *Pop(SNODE **top);
void initTree(TREE *pt);
void createTree(TREE *pt, int* arr, int n);
void printwelcometree();
void postordvisualizer();
void inordvisualizer();
void preordvisualizer();
void printpush(SNODE*st,NODE* r,int arr[],int index, char* algo);
void popprint(SNODE *st, int p,NODE *r,int arr[],int index, char* algo);
void treevisualizer();
void inorder(TREE *pt);
void preorder(TREE *pt);
void postorder(TREE *pt);
void postord(NODE *r);
void preord(NODE *r);
void inord(NODE *r);
void printstack(SNODE *st);
void printoutput(int* output, int ind);
void print2D(NODE * root);
void print2DUtil(NODE* root, int space);