#include <stdio.h>
#include <stdlib.h>
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

SNODE NewNode(NODE item);
SNODE Push(SNODE **top, NODE data);
NODE *Pop(SNODE **top);
void initTree(TREE *pt);
void createTree(TREE *pt);
void inorder(TREE *pt);
void print2DUtil(NODE* root, int space)
{
    
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
 

void print2D(NODE * root)
{
    printf("The Tree is :\n\n");
    print2DUtil(root, 0);
}
int main() {
    TREE tobj;

    initTree(&tobj);

    createTree(&tobj);
    system("cls");
    printf("Inorder traversal\n\n");
    inorder(&tobj);
    return 0;
}

void initTree(TREE *pt) {
    pt->root = NULL;
}

void createTree(TREE *pt) {
    int choice;

    NODE *temp = malloc(sizeof(NODE));
    temp->left = temp->right = NULL;
    printf("enter the info\n");
    scanf("%d", &temp->info);

    pt->root = temp;

    printf("Do you want to add one more node\n");
    scanf("%d", &choice);

    while (choice) {
        temp = malloc(sizeof(NODE));
        temp->left = temp->right = NULL;
        printf("enter the info\n");
        scanf("%d", &temp->info);

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

        printf("Do you want to add one more node\n");
        scanf("%d", &choice);
    }
}
void printpush(SNODE*st,NODE* r)
{
    
    //system("cls");
    print2D(r);
    printf("\n\n\n");
    SNODE *temp=st;
    if(!temp)
    {
        printf("\t\t\t\t\t|\t\t|\n");
        printf("\t\t\t\t\t|\t\t|\n");
        printf("\t\t\t\t\t|_______________|\n");
    }
    else{
    printf("\tPushed element: %d\n",temp->data->info);
    while(temp)
    {
        
        printf("\t\t\t\t\t|\t\t|\n");
        printf("\t\t\t\t\t|      %d",temp->data->info);printf("\t|\n");
        printf("\t\t\t\t\t|_______________|\n");
        temp=temp->next;
    }}
    
}
void popprint(SNODE *st, int p,NODE *r) {
   system("cls");
   print2D(r);
    printf("\n\n\n");
    printf("Popped element: %d ",p);
    SNODE *temp = st;
    if (!temp) {
        printf("Prints : %d\n", p);
        printf("\t\t\t\t\t|\t\t|\n");
        printf("\t\t\t\t\t|\t\t|\n");
        printf("\t\t\t\t\t|_______________|\n");
    } else {
        printf("Prints : %d\n", p);
        while (temp) {
            printf("\t\t\t\t\t|\t\t|\n");
            printf("\t\t\t\t\t|      %d", temp->data->info);
            printf("\t|\n");
            printf("\t\t\t\t\t|_______________|\n");
            temp = temp->next;
        }
    }
}

void inord(NODE *r) {
    NODE *poppedNode;
    char dummy;
    if (r != NULL) {
        SNODE *st = NULL;
        NODE *current = r;
        do {
            while (current != NULL) {
                st = Push(&st, current);
                printpush(st,r);
                printf("Press any key to continue\n");
                getchar();
                current = current->left;
            }
            int p=st->data->info;
            printf("Press any key to continue\n");
            getchar();
            poppedNode = Pop(&st);
            popprint(st,p,r);
            printf("Press any key to continue\n");
            getchar();  
            
            if (poppedNode != NULL) {
                //printf("\t\t\t\t\t\t\t\t\t\t\tPrints %d \n", poppedNode->info);
                current = poppedNode->right;
            }
        } while (st != NULL || current != NULL);
    }
}

void inorder(TREE *pt) {
    inord(pt->root);
}

SNODE NewNode(NODE data) {
    SNODE newnode = (SNODE)malloc(sizeof(SNODE));
    newnode->next = NULL;
    newnode->data = data;
    return newnode;
}

SNODE Push(SNODE **top, NODE data) {
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