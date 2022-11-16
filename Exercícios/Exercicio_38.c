#include<stdio.h>
#include<stdlib.h>

int main ()
{
	int array [10], i;
	printf("Digite 10 numeros:\n");
	for (i=0; i<10; i++){
		scanf("%d", &array [i]);
	}
	for(i=0; i<10; i++){
		if (array[i]<0){
			array[i]=0;
		}
		printf("%d ", array[i]);
	}
	return 0;
}