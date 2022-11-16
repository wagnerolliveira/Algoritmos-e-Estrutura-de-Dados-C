#include <stdio.h>
#include <stdlib.h>
int main()
{
	float num;
	printf ("digite um numero:\n");
	scanf ("%f",&num);
	if (num> 100 && num < 200){
		printf ("o numero em questao esta entre 100 e 200\n");
	}else {
		printf ("erro.Condicoes necessarias nao atendidas \n");
	}
	system ("pause");
	return 0;
}
