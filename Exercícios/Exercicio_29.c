#include<stdio.h>
#include<stdlib.h>

int main ()
{
	int array [6], i;
	printf("Digite 6 numeros:\n");
	for (i=0; i<6; i++){
		scanf("%i", &array [i]);
	}
	printf("A ordem e: ");
	for(i=0; i<6; i++){
		printf("%i ", array [i]);
	}
	return 0;
}