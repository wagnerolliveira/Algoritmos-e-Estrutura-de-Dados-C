#include<stdio.h>
#include<stdlib.h>

int main ()
{
	int matriz[5][4], i,j,soma=0, notamaior=0, aluno=0;
	float mediaf=0;
	for (i=0; i<5; i++){
		printf("-------------------------------- ALUNO %d --------------------------------\n\n", i+1);
		for (j=0; j<4; j++){
			if (j==0){
				printf("Digite o numero da matricula: ");
				scanf("%d",&matriz[i][j]);
			}else if (j==1){
				printf("Digite a media das provas: ");
				scanf("%d",&matriz[i][j]);
			}else if (j==2){
				printf("Digite a media dos trabalhos ");
				scanf("%d",&matriz[i][j]);
			}else{
				matriz[i][j]= matriz[i][1] + matriz[i][2];
				printf("Nota Final: %d\n", matriz[i][j]);
				soma+=matriz[i][j];
				if (i == 0){
					aluno = matriz[i][0];
					notamaior = matriz[i][3];
				}else{	
					if (matriz[i][3]>notamaior){
						aluno= matriz[i][0];
						notamaior = matriz[i][3];
					}	
				}
			}	
		}
	}
	
	mediaf=soma/5;
	printf("\n\nO aluno com maior nota final foi o de matricula: %d\n", aluno);
	printf("A media geral da nota final foi: %.2f\n\n", mediaf);
	return 0;
}	
