#include<stdio.h>
#include<stdlib.h>

int main ()
{
	int array [10], i, maior, posicao;
	printf("Digite 10 numeros:\n");
	for (i=0; i<10; i++){
		scanf("%d", &array [i]);
	}
	for(i=0; i<10; i++){
		printf("%d ", array [i]);
		if (i==0){
			maior=array[i];
		}
		if (maior<array[i]){
			maior=array[i];
			posicao=i;
		}
	}
	printf("\nO maior elemento e: %d\nE esta na posicao: %d\n", maior,posicao);
	return 0;
}