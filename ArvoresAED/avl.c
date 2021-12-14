#include "avl.h"
#include "processo.h"

TreeAVL* createTreeAVL(){
	return NULL;
}

void insertTreeAVL(TreeAVL **t, Record r){

  if(*t == NULL){
    *t = (TreeAVL*)malloc(sizeof(TreeAVL));
    (*t)->esq    = NULL; 
    (*t)->dir    = NULL; 
    (*t)->weight = 0;
    (*t)->reg    = r; 

  } else {
    
    if(r.key < (*t)->reg.key){
      insertTreeAVL(&(*t)->esq, r);
      if ((getWeight(&(*t)->esq) - getWeight(&(*t)->dir)) == 2){
      	if(r.key < (*t)->esq->reg.key)
      		rotacaoSimplesDireita(t);
      	else
      		rotacaoDuplaDireita(t);
      }
    }
    
    if(r.key > (*t)->reg.key){
      insertTreeAVL(&(*t)->dir, r);
      if ((getWeight(&(*t)->dir) - getWeight(&(*t)->esq)) == 2){
      	if(r.key > (*t)->dir->reg.key)
      		rotacaoSimplesEsquerda(t);
      	else
      		rotacaoDuplaEsquerda(t);
      }
    }
  
  }

  (*t)->weight = getMaxWeight(getWeight(&(*t)->esq), getWeight(&(*t)->dir)) + 1;

}

void pesquisaAVL(TreeAVL **t, TreeAVL **aux, Record r){

	if(*t == NULL){return;}

	if((*t)->reg.key > r.key){ pesquisaAVL(&(*t)->esq, aux, r); return;}
	if((*t)->reg.key < r.key){ pesquisaAVL(&(*t)->dir, aux, r); return;}

	*aux = *t;
}


void rebalanceTreeAVL(TreeAVL **t){
	int balance;
  	int left = 0;
  	int right = 0;

	balance = getWeight(&(*t)->esq) - getWeight(&(*t)->dir);
	if((*t)->esq)
		left = getWeight(&(*t)->esq->esq) - getWeight(&(*t)->esq->dir);
	if((*t)->dir)
		right = getWeight(&(*t)->dir->esq) - getWeight(&(*t)->dir->dir);

	if(balance == 2 && left >= 0)
		rotacaoSimplesDireita(t);
	if(balance == 2 && left < 0)
		rotacaoDuplaDireita(t);

	if(balance == -2 && right >= 0)
		rotacaoDuplaEsquerda(t);
	if(balance == -2 && right < 0)
		rotacaoSimplesEsquerda(t); 	
}

int getWeight(TreeAVL **t){
	if(*t == NULL)
		return -1;
	return (*t)->weight;
}

int getMaxWeight(int left, int right){
	if(left > right)
		return left;
	return right;
}

void rotacaoSimplesDireita(TreeAVL **t){
	TreeAVL *aux;
	aux = (*t)->esq;
	(*t)->esq = aux->dir;
	aux->dir = (*t);
	(*t)->weight = getMaxWeight(getWeight(&(*t)->esq), getWeight(&(*t)->dir)) + 1;
	aux->weight  = getMaxWeight(getWeight(&aux->esq), (*t)->weight) + 1;
	(*t) = aux;
}

void rotacaoSimplesEsquerda(TreeAVL **t){
	TreeAVL *aux;
	aux = (*t)->dir;
	(*t)->dir = aux->esq;
	aux->esq = (*t);
	(*t)->weight = getMaxWeight(getWeight(&(*t)->esq), getWeight(&(*t)->dir)) + 1;
	aux->weight  = getMaxWeight(getWeight(&aux->esq), (*t)->weight) + 1;
	(*t) = aux;
}

void rotacaoDuplaDireita(TreeAVL **t){
	rotacaoSimplesEsquerda(&(*t)->esq);
	rotacaoSimplesDireita(t);
}

void rotacaoDuplaEsquerda(TreeAVL **t){
	rotacaoSimplesDireita(&(*t)->dir);
	rotacaoSimplesEsquerda(t);
}

void auxInsertAVL(TreeAVL **t,int qnt){
	
	Record recordAVL;

    srand(time(NULL));
    float a = 5;

    for(int i=0;i<qnt;i++){  		
		recordAVL.key= ((float)rand()/(float)(RAND_MAX))*a;
		recordAVL.value=1;
		insertTreeAVL(t,recordAVL);	
	}
}

void centralAVL(TreeAVL *t){
    
    if(!(t == NULL)){
        centralAVL(t->esq); 
        printf("%f | ", t->reg.key);
        centralAVL(t->dir); 
    }
}

void auxPesquisaAVL(int search,TreeAVL **t,int *discovery){
     
    
    Record recordAVL;
    srand((unsigned int)time(NULL));
    int cont=0;
    float a = 5;

    for(int i=0;i<search;i++){ 
        TreeAVL *aux = createTreeAVL(); 		
		recordAVL.key= ((float)rand()/(float)(RAND_MAX))*a;
		recordAVL.value=1;
		pesquisaAVL(t,&aux,recordAVL);
        if(aux != NULL) cont++;
	}	

	*discovery = cont;
}

