#include "processo.h"

void arrowHere(int realPosition,int arrowPosition){
	
	if(realPosition == arrowPosition){
		printf(" ---->> - ");
	}else{
		printf("         ");
	}
}

void menu(int *data,int *tree){  
	
	system("cls");
	int keyPressed=0;
	int chooseData=1;
	int chooseTree=1;

	while(keyPressed !=13){

		system("cls");

		printf("\tEscolha a estrutura a ser utilizada: \n\n");

		arrowHere(1,chooseTree); printf("Arvore binaria\n");
		arrowHere(2,chooseTree); printf("AVL\n");
		arrowHere(3,chooseTree); printf("Red-Black\n");

		keyPressed = getch();

		if(keyPressed==80 && chooseTree!=MAX){
			chooseTree++;
		}else if(keyPressed==72 && chooseTree!=MIN){
			chooseTree--;
		}else{
			chooseTree=chooseTree;
		}
	}

	*tree = chooseTree;

	keyPressed=0;

	while(keyPressed !=13){
		system("cls");

		printf("\tEscolha a base de dados: \n\n");

		arrowHere(1,chooseData); printf("Base com 1000 entradas\n");
		arrowHere(2,chooseData); printf("Base com 10000 entradas\n");
		arrowHere(3,chooseData); printf("Base com 1000000 entradas\n");

		keyPressed = getch();

		if(keyPressed==80 && chooseData!=MAX){
			chooseData++;
		}else if(keyPressed==72 && chooseData!=MIN){
			chooseData--;
		}else{
			chooseData=chooseData;
		}
	}

	switch (chooseData){
		case 1: 
			*data=1000;		
		break;

		case 2:
			*data=10000;			
		break;

		case 3:
			*data=1000000;			
		break;
	}
}

void menuSearch(int *search){

	system("cls");
	int keyPressed=0;
	int chooseSearch=1;
	

	while(keyPressed !=13){

		system("cls");

		printf("\tEscolha a base de pesquisa a ser utilizada: \n\n");

		arrowHere(1,chooseSearch); printf("5000 itens\n");
		arrowHere(2,chooseSearch); printf("10000 itens\n");
		arrowHere(3,chooseSearch); printf("100000 itens\n");

		keyPressed = getch();

		if(keyPressed==80 && chooseSearch!=MAX){
			chooseSearch++;
		}else if(keyPressed==72 && chooseSearch!=MIN){
			chooseSearch--;
		}else{
			chooseSearch=chooseSearch;
		}
	}

	switch (chooseSearch){
		case 1: 
			*search=5000;
		break;

		case 2:
			*search=10000;			
		break;

		case 3:
			*search=100000;			
		break;
	}
}


void result(int data, int search,int discovery){



	printf("\n\n");
    printf("      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("      @                                                 @\n");
    printf("      @                    RESULTADOS                   @\n");
    printf("      @                             					\n");
    printf("      @         Itens inseridos: %d						\n",data);
    printf("      @         Itens procurados: %d					\n",search);
    printf("      @         Itens encontrados: %d					\n",discovery);
    printf("      @                                                 @\n");
    printf("      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n");
}
