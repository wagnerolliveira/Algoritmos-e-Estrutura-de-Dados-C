#include <stdio.h>
#include <stdlib.h>
int main()
{
	float a,b,soma=0;
	print("O programa se encerrará quando digitar um numero entre 1 e 100");
	while( a<1 || a > 100 || b<1 || b >100){
		printf("digite dois numeros reais:\n");
		scanf ("%f %f",&a,&b);
		soma = a + b;
	}
	printf ("a soma dos numeros eh %2.f",soma);
	system ("pause");
	return 0;
}
