#include<stdio.h>
#include<stdlib.h>

int main ()
{
	int matriza [4][4],matrizb [4][4],matrizc [4][4], i, j;
	printf("Preencha a primeira matriz:\n");
	for (i=0; i<4; i++){
		for (j=0; j<4; j++){
			printf("\nElemento [%d][%d]", i, j);
			scanf("%d", &matriza [i][j]);
		}
	}
	printf("Preencha a segunda matriz:\n");
	for (i=0; i<4; i++){
		for (j=0; j<4; j++){
			printf("\nElemento [%d][%d]", i, j);
			scanf("%d", &matrizb [i][j]);
		}
	}
	for (i=0; i<4; i++){
		for (j=0; j<4; j++){
			if (matriza[i][j]> matrizb[i][j]){
				matrizc [i][j]= matriza[i][j];
			}else {
				matrizc [i][j]= matrizb[i][j];
			}
		}
	} 
	for (i=0; i<4; i++){
		printf("\n");
		for (j=0; j<4; j++){
			printf("%d  ", matrizc[i][j]);
		}
	}		
	return 0;
}