#include<stdio.h>
#include<stdlib.h>

int main ()
{
	int matriz [4][4], i, j, contador=0;
	printf("Preencha a matriz:\n");
	for (i=0; i<4; i++){
		for (j=0; j<4; j++){
			printf("\nElemento [%d][%d]", i, j);
			scanf("%d", &matriz [i][j]);
			if (matriz [i][j]<10){
				contador++;
			}
		}
	}
	printf("Contem %d numeros maiores que 10", contador);
	return 0;
}