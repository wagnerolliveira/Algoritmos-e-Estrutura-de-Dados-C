#include<stdio.h>
#include<stdlib.h>

int main ()
{
	int b,e, i, potencia=1;
	printf ("Digite a base\n");
	scanf("%d", &b);
	printf ("Digite o expoente\n");
	scanf("%d", &e);
	for (i=1; i<=e; i++){
		potencia*= b;
	}
	printf("%d\n", potencia);
	system("pause");
	return 0;
}