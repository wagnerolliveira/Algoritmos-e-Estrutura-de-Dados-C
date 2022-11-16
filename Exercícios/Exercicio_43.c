#include<stdio.h>
#include<stdlib.h>

int main ()
{
	int matriz [5][5], i, j, x, achou=0;
	printf("Preencha a matriz:\n");
	for (i=0; i<5; i++){
		for (j=0; j<5; j++){
			printf("\nElemento [%d][%d]", i, j);
			scanf("%d", &matriz [i][j]);
		}
	}
	printf("Qual o elemento voce deseja encontrar?\n");
	scanf("%d", &x);
	for (i=0; i<5; i++){
		for (j=0; j<5; j++){
			if (matriz [i][j]==x){
				achou++;
				printf("Linha %d   Coluna %d\n", i, j);
			}
		}
	}
	if (achou!= 0){
		printf("Foram encontrados %d elementos\n", achou);
	}else {
		printf("Nao encontrado\n");
	}
	
	return 0;
}