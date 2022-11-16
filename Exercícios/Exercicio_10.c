#include <stdio.h>
#include <stdlib.h>
int main()
{
	float nota1,nota2,nota3,nota4,media,recup,mediaf;
	printf("Informe a suas 4 notas sendo elas de 0 a 10:\n");
	scanf("%f %f %f %f",&nota1,&nota2,&nota3,&nota4);
	media = (nota1 + nota2 + nota3 + nota4)/4;
	if (media >= 7){
	    printf ("Aprovado!\n");
	}else {
	    printf("Informe a nota da avalicao de recuperacao:\n");
	    scanf ("%f",&recup);
	    mediaf = (nota1 + nota2 + nota3 + nota4 + recup)/5;
    	if (mediaf >= 7){
   	   		printf ("Aprovado.\n");
		}else {
	        printf ("Reprovado.\n");
	    }
	}
	system ("pause");
	return 0;
}
