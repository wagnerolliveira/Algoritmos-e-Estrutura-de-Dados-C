#include<stdio.h>
#include<stdlib.h>

int main ()
{
	float array [10],soma=0;;
	int i, contador=0;
	printf("Digite 10 numeros:\n");
	for (i=0; i<10; i++){
		scanf("%f", &array [i]);
	}
	for(i=0; i<10; i++){
		if (array[i]<0){
			contador++;
		}
		else {
			soma+=array[i];
		}
	}
	printf("A soma dos numeros positivos e: %.2f\nContem %d numeros negativos\n", soma,contador);
	return 0;
}