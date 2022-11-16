#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main ()
{
	float area,raio;
	printf ("Digite um valor para o raio do circulo\n");
	scanf("%f",&raio);
	area = M_PI*raio*raio;
	
	printf ("0 valor da area e: %.2f\n",area);
	system ("pause");
	return 0;
}