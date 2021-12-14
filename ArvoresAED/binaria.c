#include "binaria.h"
#include "processo.h"

TreeBinary* createTreeBinary(){
    return NULL;
}

void insertBinary(TreeBinary **t, RecordBinary r){
    
    if(*t == NULL){
        *t = (TreeBinary*)malloc(sizeof(TreeBinary));
        (*t)->esq = NULL;
        (*t)->dir = NULL;
        (*t)->reg = r;
    }else{
 
        if(r.key < (*t)->reg.key)
            insertBinary(&(*t)->esq,r);

        if(r.key > (*t)->reg.key)
            insertBinary(&(*t)->dir,r);
    } 
}

void pesquisaBinary(TreeBinary **t, TreeBinary **aux, RecordBinary r){

  if(*t == NULL){return;}

  if((*t)->reg.key > r.key){ pesquisaBinary(&(*t)->esq, aux, r); return;}
  if((*t)->reg.key < r.key){ pesquisaBinary(&(*t)->dir, aux, r); return;}

  *aux = *t;
}

void central(TreeBinary *t){
    
    if(!(t == NULL)){
        central(t->esq); 
        printf("%f | ", t->reg.key);
        central(t->dir); 
    }
}


void auxInsertBinary(TreeBinary **t,int qnt){

    RecordBinary recordBinary;
    srand(time(NULL));
    float a = 5; 
    for(int i=0;i<qnt;i++){  
            recordBinary.key= ((float)rand()/(float)(RAND_MAX))*a;
		    recordBinary.value=1;
		    insertBinary(t,recordBinary);	      
	}	
}

void auxPesquisaBinary(int search,TreeBinary **t,int *discovery){
    
    RecordBinary recordBinary;
    srand((unsigned int)time(NULL));
    int cont=0;
    float a = 5;
    for(int i=0;i<search;i++){         
            TreeBinary *aux = createTreeBinary(); 		  
		    recordBinary.key= ((float)rand()/(float)(RAND_MAX))*a;
    	    recordBinary.value=1;
		    pesquisaBinary(t,&aux,recordBinary);
            if(aux != NULL) cont++;
	}	
    *discovery = cont;
}
