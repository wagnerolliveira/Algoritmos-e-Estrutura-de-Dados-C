#include<stdio.h>
#include<stdlib.h>

int main()

{
	float valor, salario, porcent=0, parcela=0;
	int nparc;
	printf("Qual o valor do emprestimo?\n");
	scanf ("%f", &valor);
	printf("Em quantas vezes deseja pagar?\n");
	scanf ("%d", &nparc);
	printf("Qual e o seu salario?\n");
	scanf ("%f", &salario);
	parcela= valor/nparc;
	porcent= salario *0.3;
	if (parcela <=porcent){
		printf("Emprestimo aprovado\nSuas parcelas serao no valor de %.2f\n\n", parcela);
	}else {
		printf ("Emprestimo nao aprovado\n");
	}
	system("pause");
	return 0;
}