#include<stdio.h>
#include<stdlib.h>

int main ()
{
	int array [10], i, contador_pares=0, pares;
	printf("Digite 10 numeros:\n");
	for (i=0; i<10; i++){
		scanf("%d", &array [i]);
	}
	printf("Os numeros pares sao: ");
	for(i=0; i<10; i++){
		pares= array[i]%2;
		if (pares==0){
			contador_pares++;
			printf ("%d ", array[i]);
		}	
	}
	printf("\nO conjunto tem um total de %d pares",contador_pares);
	return 0;
}