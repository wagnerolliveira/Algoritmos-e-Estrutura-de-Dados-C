#include <stdio.h>
#include <stdlib.h>
int main()
{
	int quant,i;
	float altura,soma,media;
	soma = 0;
	printf ("\nDigite a quantidade de jogadores que deseja: ");
	scanf ("%d",&quant);
	for(i=0;i<quant;i++ ){
	    printf("\ninforma a altura do jogador: ");
	    scanf("%f",&altura);
	    soma = soma + altura;
	}
	media = soma/quant;
	printf ("altura media: %.2f",media);
	system("pause");
	return 0;
}


