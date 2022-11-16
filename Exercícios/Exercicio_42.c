#include<stdio.h>
#include<stdlib.h>

int main ()
{
	int matriz [4][4], i, j,maior, lin, col;
	printf("Preencha a matriz:\n");
	for (i=0; i<4; i++){
		for (j=0; j<4; j++){
			printf("\nElemento [%d][%d]", i, j);
			scanf("%d", &matriz [i][j]);
		}
			
	}
	for (i=0; i<4;i++){
		printf("\n");
		for (j=0; j<4; j++){
			printf("%d    ", matriz[i][j]);
			if ((i==0) && (j==0)){
				maior=matriz[i][j];
			}
			if (matriz [i][j]>maior){
				maior=matriz[i][j];
				lin=i;
				col=j;
			}
		}	
	}
	printf("\nO maior elemento esta na linha %d coluna %d", lin, col);
	return 0;
}