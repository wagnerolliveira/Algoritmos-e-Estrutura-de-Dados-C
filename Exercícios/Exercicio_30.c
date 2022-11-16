#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main ()
{
	char nome [46];
	int i, j, tam;
	for (i=0;i<3; i++){
		printf("Digite uma palavra: \n");
		gets(nome);
		tam = strlen(nome);
		printf("A palavra de tras pra frente e: \n");
		for (j=tam-1; j >= 0; j--){
			printf("%c",nome[j]);
		}
		printf("\n\n");
	}
	return 0;
}