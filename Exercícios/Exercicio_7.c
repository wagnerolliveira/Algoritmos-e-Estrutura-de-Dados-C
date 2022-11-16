#include<stdio.h>
#include<stdlib.h>

int main()

{
	int idade;
	printf("Informe sua idade\n");
	scanf("%d",&idade);
	if (idade >=18){
		printf("Voce ja e maior de idade\n");
	}else {
		printf("Voce ainda e menor de idade\n");
	}
	system("pause");
	return 0;
}