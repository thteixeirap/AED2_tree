#include "avl.h"
#include "binaria.h"
#include "rb.h"
#include "processo.h"

int main(){

	TreeBinary *rootBinary = createTreeBinary();
	TreeAVL *rootAVL = createTreeAVL();
	TreeRB *rootRB = T_Nil;
	int data=0;
	int tree=0;
	int search=0;
	int discovery=0;
	clock_t start,stop,start1,stop1;
	double elapsed,elapsed1;

	menu(&data,&tree); 

	switch (tree){
		case 1: //Binária
			start1 = clock();
			auxInsertBinary(&rootBinary,data); // Função com um insert dentro de um for
			stop1 = clock();
			menuSearch(&search);
		
			start = clock();
			auxPesquisaBinary(search,&rootBinary,&discovery);
			stop = clock();

			
			elapsed1 = (double)(stop1 - start1) * 1000.0 / CLOCKS_PER_SEC;
			printf("\n\n\n\tTempo de insercao em ms: %f\n", elapsed1);
		
			elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
    		printf("\tTempo pesquisa em ms: %f\n", elapsed);
			result(data,search,discovery);

		break;

		case 2: //AVL
			start1 = clock();
			auxInsertAVL(&rootAVL,data);
			stop1 = clock();

			menuSearch(&search);
		
			start = clock();
			auxPesquisaAVL(search,&rootAVL,&discovery);
			stop = clock();

			elapsed1 = (double)(stop1 - start1) * 1000.0 / CLOCKS_PER_SEC;
			printf("Tempo de insercao em ms: %f\n", elapsed1);

			elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
			printf("Tempo pesquisa em ms: %f", elapsed);
			result(data,search,discovery);
		break;
			
		case 3: 

			
			start1 = clock();
   			auxInsertRB(&rootRB,data);
			stop1 = clock();

			menuSearch(&search);

			start = clock();
   			auxPesquisaRB(search,&rootRB,&discovery);
			stop = clock();

			
			elapsed1 = (double)(stop1 - start1) * 1000.0 / CLOCKS_PER_SEC;
			printf("\n\n\n\tTempo de insercao em ms: %f\n", elapsed1);
		
			elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
    		printf("\tTempo pesquisa em ms: %f\n", elapsed);
			result(data,search,discovery);
    	
		break;
	}
	return 0;
}

