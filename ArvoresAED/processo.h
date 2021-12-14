#ifndef PROCESSO_H 
#define PROCESSO_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <windows.h>
#include <stdbool.h> 
#include <string.h>

#define MAX 3
#define MIN 1

void arrowHere(int realPosition,int arrowPosition);
void menu(int *data,int *tree);
void menuSearch(int *search);
bool Existe (float valores[],int tam,float valor);
void result(int data, int search,int discovery);

#endif