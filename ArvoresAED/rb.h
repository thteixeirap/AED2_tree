/*#ifndef RB_H
#define RB_H

#include<stdio.h>
#include<stdlib.h>

#define RED   1
#define BLACK 0

typedef struct Node {
    int          key;
    int         color;
    struct Node *esq;
    struct Node *dir;
    struct Node *pai;
} Node;


struct Node  T_Nil_Node;
Node* T_Nil ;
Node* Root = NULL;


Node* createTreeRB(int key);
void rotateesq( Node** T, Node* x);
void rotateRight(Node** T, Node* y);
void redBlackInsertFixup(Node** Root, Node* z);
void redBlackInsert(Node** T, int key);
void printTree(Node* root);
int height(Node* Root);
void pesquisaRB(Node** t, Node** aux, int val);

#endif*/  //PARA -----
#include<stdio.h>
#include<stdlib.h>
#include <time.h>

#define RED   1
#define BLACK 0


typedef struct TreeRB {
    float          key;
    int         color;
    struct TreeRB *esq;
    struct TreeRB *dir;
    struct TreeRB *pai;
} TreeRB;

struct TreeRB  T_Nil_Node;
TreeRB* T_Nil = &T_Nil_Node;

TreeRB* Root = NULL;

TreeRB* createTreeRB(float key)
{
    TreeRB *tio = (TreeRB*) malloc(sizeof(TreeRB));
    tio->key    = key;
    tio->color  = RED;
    tio->esq    = NULL;
    tio->dir    = NULL;
    tio->pai    = NULL;

    return tio;
}

void rotateLeft( TreeRB** T, TreeRB* x)
{
    TreeRB *y  = x->dir;   
    x->dir = y->esq;     
    if (y->esq != T_Nil)
        y->esq->pai = x;
    y->pai = x->pai;  
    if (x->pai == T_Nil) 
        *T = y;
    else if (x == x->pai->esq)
        x->pai->esq = y;
    else
        x->pai->dir = y;
    y->esq   = x;           
    x->pai = y;
}

void rotateRight(TreeRB** T, TreeRB* y)
{
    TreeRB *x  = y->esq;
    y->esq  = x->dir;    
    if (x->dir != T_Nil)
        x->dir->pai = y;
    x->pai = y->pai;
    if (y->pai == T_Nil)
        *T = x;
    else if (y == y->pai->dir)
        y->pai->dir = x;
    else
        y->pai->esq  = x;
    x->dir  = y;         
    y->pai = x;
}

void redBlackInsertFixup(TreeRB** Root, TreeRB* z)
{
    TreeRB* tio;
    
    while (z->pai->color == RED)
    {
        if (z->pai == z->pai->pai->esq)
        {
            tio = z->pai->pai->dir;
            if (tio->color == RED)
            {
                z->pai->color = BLACK;
                tio->color = BLACK;
                z->pai->pai->color = RED;
                z = z->pai->pai;
            }
            else {
                if (z == z->pai->dir)
                {
                    z = z->pai;
                    rotateLeft(Root, z);
                }
                z->pai->color = BLACK;
                z->pai->pai->color = RED;
                rotateRight(Root, z->pai->pai);
            }
        }
        else
        {
            tio = z->pai->pai->esq;
            if (tio->color == RED)
            {
                z->pai->color = BLACK;
                z->color = BLACK;
                z->pai->pai->color = RED;
                z = z->pai->pai;
            }
            else {
                if (z == z->pai->esq)
                {
                    z = z->pai;
                    rotateRight(Root, z);
                }
                z->pai->color = BLACK;
                z->pai->pai->color = RED;
                rotateLeft(Root, z->pai->pai);
            }
        }
    }
    Root[0]->color = BLACK;
}
void redBlackInsert(TreeRB** T, float key)
{
    TreeRB* z =  createTreeRB(key);
    TreeRB* y =  T_Nil;
    TreeRB* x = *T;
     
    while (x != T_Nil) {
        y = x;
        if (z->key < x->key)
            x = x->esq;
        else
            x = x->dir;
    }
    z->pai = y;
  
    if (y == T_Nil)
        *T = z;
    else if (z->key < y->key)
        y->esq  = z;
    else
        y->dir = z;

    z->esq  = T_Nil;
    z->dir = T_Nil;
    z->color = RED;

    redBlackInsertFixup(T, z);
}

void pesquisaRB(TreeRB** t, TreeRB** aux,float val){


	if(*t == NULL){
		//printf("[ERROR]: Node not found!\n");
		return;
	}

	if((*t)->key > val){ pesquisaRB(&(*t)->esq, aux, val); return;}
	if((*t)->key < val){ pesquisaRB(&(*t)->dir, aux, val); return;}

	*aux = *t;
}

void auxInsertRB(TreeRB **t,int cont){

    srand((unsigned int)time(NULL));
    float a = 5; 
    float num;
    for(int i=0; i<cont;i++){  
        num = ((float)rand()/(float)(RAND_MAX))*a;
		redBlackInsert(t,num);	      
	}	
}


void auxPesquisaRB(int search,TreeRB **t,int *discovery){
    

      srand((unsigned int)time(NULL));
    int cont=0;
    float a = 5;
    float num;

    for(int i=0;i<search;i++){    
            TreeRB *aux = NULL;	  
		    num = ((float)rand()/(float)(RAND_MAX))*a;
		    pesquisaRB(t,&aux,num);
            //printf("Pesquisado: %.2f",num);
            if(aux !=NULL) cont++;
	}	
    *discovery = cont;
}