#include <stdio.h>
#include <stdlib.h>
int main()
{
	float num,soma;
	soma = 0;
	printf ("\ndigite numeros para ser somados e 0 para sair: ");
	scanf("%f",&num);
	while(num != 0){
	    soma = soma + num;
	    printf("A soma e aproximadamente: %.2f\n", soma);
	    printf ("\ndigite numeros para ser somados e 0 para sair: ");
	    scanf("%f",&num);
	}
	return 0;
	system("pause");
}

