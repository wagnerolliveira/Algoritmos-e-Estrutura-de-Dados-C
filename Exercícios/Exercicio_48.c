#include<stdio.h>
#include<stdlib.h>

int main ()
{
	char gab[10], aluno[10];
	int op, i, nota;
	printf("Digite o Gabarito:\n");
	for (i=0; i<10; i++){
		printf("QUESTAO [%d]", i+1);
		scanf("%c", &gab[i]);
		setbuf(stdin,NULL);
		while(gab[i] != 'A' && gab[i] != 'B'&& gab[i] != 'C' && gab[i] != 'D'){
			printf("Valor invalido! Digite novamente!\n");
			printf("QUESTAO [%d]",i+1);
			scanf("%c", &gab[i]);
			setbuf(stdin,NULL);
		}
	}
	do{
		printf("----------------------- ALUNO ----------------------- \n");
		setbuf(stdin,NULL);
		nota=0;
		
		for (i=0; i<10; i++){
			printf("QUESTAO [%d]", i+1);
			scanf("%c", &aluno[i]);
			setbuf(stdin,NULL);
			while(aluno[i] != 'A' && aluno[i] != 'B'&& aluno[i] != 'C' && aluno[i] != 'D'){
				printf("Valor invalido! Digite novamente!\n");
				printf("QUESTAO [%d]",i+1);
				scanf("%c", &aluno[i]);
				setbuf(stdin,NULL);
			}
		}
		for (i=0; i<10; i++){
			if (gab[i]==aluno[i]){
				nota++;
			}
		}
		printf("O Aluno tirou: %d\n", nota);
		if (nota>=7){
			printf("APROVADO\n");
		}else {
			printf("REPROVADO\n");
		}
		printf("DIGITE 1 PARA VERIFICAR A NOTA DE UM NOVO ALUNO OU QUALQUER TECLA PARA FINALIZAR O PROGRAMA\n");
		scanf("%d", &op);
	}while(op==1);	
	return 0;
}