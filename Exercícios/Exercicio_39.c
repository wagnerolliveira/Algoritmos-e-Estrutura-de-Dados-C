#include<stdio.h>
#include<stdlib.h>

int main ()
{
	float array [10];
	int i, op;
	printf("Digite 10 numeros:\n");
	for (i=0; i<10; i++){
		scanf("%f", &array [i]);
	}
	printf("xxxxxxxxxxxxxxxxxxx OPCOES xxxxxxxxxxxxxxxxxxx\n");
	printf("1-Finalizar Programa\n2-Imprimir ordem\n3-Imprimir ordem inversa\n");
	scanf("%d", &op);
	switch(op){
	case 1:
		break;
	case 2:
		printf("A ordem e: ");
		for (i=0; i<10; i++){
			printf("%.1f ", array [i]);
		}
		break;
	case 3:
		printf("A ordem inversa e: ");
		for (i=9; i>=0; i--){
			printf("%.1f ", array [i]);
		}
		break;
	default:
		printf("Opcao Invalida!!");
		break;
	}
	return 0;
}