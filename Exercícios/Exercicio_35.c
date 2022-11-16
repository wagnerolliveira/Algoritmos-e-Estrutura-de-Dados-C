#include<stdio.h>
#include<stdlib.h>

int main ()
{
	int array [15], i, soma=0, media;
	printf("Digite as 15 notas:\n");
	for(i = 0; i < 15; i++){
		printf("Digite a nota %d: ", i+1);
		scanf("%d", &array[i]);
		while(array[i] < 0 || array[i] > 10){
			printf("Valor invalido! Digite novamente!\n");
			printf("Digite a nota %d: ", i+1);
			scanf("%d", &array[i]);
		}
	}
	for(i=0; i<15; i++){
		soma+=array[i];
	}
	media=soma/15;
	printf("A media geral e: %d", media);
	return 0;
}