#ifndef BINARIA_H 
#define BINARIA_H

#include<stdio.h>
#include<stdlib.h>
#include <time.h>

typedef struct RecordBinary RecordBinary;
typedef struct TreeBinary TreeBinary;

struct RecordBinary{
	float key;
	float value;
};

struct TreeBinary{
	RecordBinary reg;
	TreeBinary *esq, *dir;
};

TreeBinary* createTreeBinary();
void insertBinary(TreeBinary **t, RecordBinary r);
void pesquisaBinary(TreeBinary **t, TreeBinary **aux, RecordBinary r);
void central(TreeBinary *t);
void auxInsertBinary(TreeBinary **t,int qnt);
void auxPesquisaBinary(int search,TreeBinary **t,int *discovery);

#endif