#include <stdlib.h>
#include <stdio.h>
#define MAX_ALUNOS 10
int main()
{
	float nota1,nota2,media;
	int i;
	for (i=0;i<MAX_ALUNOS;i++){
		printf("Ordem de chamada dos alunos:\n ");
	    printf("Entre com a primeira nota (0 a 10):\n ");
   	 	do {
			scanf("%f", &nota1);
            if(nota1 < 0 || nota1 > 10) {
                printf("Erro, valor deve ser de 0 a 10 \n");
			}
	
		}while(nota1 < 0 || nota1 > 10);{}
		printf("Entre com a segunda nota (0 a 10): ");
    	do {
			scanf("%f", &nota2);
      	  	if(nota2 < 0 || nota2 > 10){
				printf("Erro, valor deve ser de 0 a 10 \n");
			}		   	
        }while(nota2 < 0 || nota2 > 10);
	
		media = (nota1+nota2)/2;
		printf ("A media do %d aluno foi: %f\n",i+1,media);
		printf ("-----------------\n");
	}
	system ("pause");
	return 0;
}

