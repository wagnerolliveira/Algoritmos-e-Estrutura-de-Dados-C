#include<stdio.h>
#include<stdlib.h>

int main ()
{
	int array [5], i, maior, menor, pos_maior=0, pos_menor;
	printf("Digite 5 numeros:\n");
	for (i=0; i<5; i++){
		scanf("%d", &array [i]);
		if(i==0){
			maior=array[i];
			menor=array[i];
			pos_maior=i;
			
		}
		if (maior<array [i]){
			maior=array[i];
			pos_maior =i;
		}else if (menor>array[i]){
			menor=array[i];
			pos_menor=i;
		}
	}
	printf ("O Maior e: %d e esta na posicao: %d\n", maior, pos_maior);
	printf ("O Menor e: %d e esta na posicao: %d\n", menor, pos_menor);
	return 0;
}