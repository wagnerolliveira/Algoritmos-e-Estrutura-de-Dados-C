#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>

int main ()
{
	int array [10], res [10], i, quadrado;
	printf("Digite 10 numeros:\n");
	for (i=0; i<10; i++){
		scanf("%d", &array [i]);
		quadrado= pow(array [i],2);
		res [i]=quadrado;
	}
	for (i=0; i<10; i++){
		Sleep (500);
		printf("%d ",res [i]);
	}
	return 0;
}