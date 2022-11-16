#include<stdio.h>
#include<stdlib.h>

int main ()
{
	int array [10], i, maior, menor;
	printf("Digite 10 numeros:\n");
	for (i=0; i<10; i++){
		scanf("%d", &array [i]);
		if(i==0){
			maior=array[i];
			menor=array[i];
		}
		if (maior<array [i]){
			maior=array[i];
		}else if (menor>array[i]){
			menor=array[i];
		}
	}
	printf ("O Maior e: %d e o Menor e: %d", maior, menor);
	
	return 0;
}