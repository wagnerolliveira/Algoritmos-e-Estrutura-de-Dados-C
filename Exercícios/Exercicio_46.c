#include<stdio.h>
#include<stdlib.h>

int main ()
{
	int matriz[4][4], i,j;
	printf("Preencha a matriz:\n");
	for (i=0; i<4; i++){
		for (j=0; j<4; j++){
			printf("\nElemento [%d][%d]", i, j);
			scanf("%d", &matriz[i][j]);
			while(matriz[i][j] < 1 || matriz[i][j] > 20){
				printf("Valor invalido! Digite novamente!\n");
				printf("Elemento [%d][%d]", i, j);
				scanf("%d", &matriz[i][j]);
			}
		}
	}
	for (i=0; i<4; i++){
		printf("\n");
		for (j=0; j<4; j++){
			printf("%d\t", matriz[i][j]);
		}	
	}
	printf("\n\n");	
	for (i=0; i<4; i++){
		printf("\n");
		for (j=0; j<4; j++){
			if (i<j){
				matriz[i][j]=0;
				printf("%d\t", matriz[i][j]);
			}else {
				printf("%d\t", matriz[i][j]);
			}
			
		}	
	}	
	return 0;
}
