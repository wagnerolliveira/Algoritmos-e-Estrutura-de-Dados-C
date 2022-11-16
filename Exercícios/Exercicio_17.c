#include<stdio.h>
#include<stdlib.h>

int main()

{
	int num, soma=0, i=0;
	printf("Digite 10 numeros\n");
	for (i=0; i<10; i++){
		scanf("%d", &num);
		soma += num;
	}
	printf("%d \n", soma);
	system("pause");
	return 0;
}