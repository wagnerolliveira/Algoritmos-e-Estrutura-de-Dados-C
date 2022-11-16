#include<stdio.h>
#include<stdlib.h>

int main()

{
	float lp, ap, la, aa, areaa=0, areap=0, azulejo=0;
	printf("Digite as dimencoes da parede(largura e altura) em metros\n");
	scanf("%f %f", &lp, &ap);
	printf("Digite as dimencoes do azulejo(largura e altura) em metros\n");
	scanf("%f %f", &la, &aa);
	areaa= la*aa;
	areap= lp*ap;
	azulejo= areap/areaa;
	printf("A quantidade de azulejos necessarios para cobrir a parede e %.0f\n\n", azulejo);
	system("pause");
	return 0;
}