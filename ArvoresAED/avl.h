#ifndef AVL_H 
#define AVL_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <windows.h>
#include <math.h>
#include <time.h>

typedef struct Record Record;
typedef struct TreeAVL TreeAVL;

struct Record{
	float key;
	float value;
};

struct TreeAVL{
	Record reg;
	TreeAVL *esq, *dir;
	int weight;
};

TreeAVL* createTreeAVL();
void insertTreeAVL(TreeAVL **t, Record r);
void pesquisaAVL(TreeAVL **t, TreeAVL **aux, Record r);
int isInTreeAVL(TreeAVL *t, Record r);

void rebalanceTreeAVL(TreeAVL **t);

int getWeight(TreeAVL **t);
int getMaxWeight(int left, int right);

void rotacaoSimplesDireita(TreeAVL **t);
void rotacaoSimplesEsquerda(TreeAVL **t);
void rotacaoDuplaDireita(TreeAVL **t);
void rotacaoDuplaEsquerda(TreeAVL **t);
void auxInsertAVL(TreeAVL **t,int qnt);
void centralAVL(TreeAVL *t);
void auxPesquisaAVL(int search,TreeAVL **t,int* discovery);
#endif