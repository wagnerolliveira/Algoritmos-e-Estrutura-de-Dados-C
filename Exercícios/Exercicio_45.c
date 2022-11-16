#include<stdio.h>
#include<stdlib.h>

int main ()
{
	int matriz[3][3],i, j, soma=0;
	printf("Preencha a matriz:\n");
	for (i=0; i<3; i++){
		for (j=0; j<3; j++){
			printf("\nElemento [%d][%d]", i, j);
			scanf("%d", &matriz[i][j]);
			if (i==j){
				soma+=matriz[i][j];
			}
		}
	}
	printf("A soma dos elementos da diagonal principal e: %d", soma);
	return 0;
}	