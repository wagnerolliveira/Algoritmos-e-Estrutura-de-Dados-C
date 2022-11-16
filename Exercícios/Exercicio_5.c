#include<stdio.h>
#include<stdlib.h>

int main()

{
	int op1,op2;
	printf("Qual o seu sexo?\n1-Feminino\n2-Masculino\n");
	scanf("%d", &op1);
	printf("Voce tem algum problema de saude?\n1-Sim\n2-Nao\n");
	scanf("%d", &op2);
	switch (op1){
		case 1:
			switch (op2){
				case 1:
					printf("Voce nao pode se alistar\n\n");
					break;
				case 2:
					printf("Voce nao pode se alistar\n\n");
					break;
				default:
					printf("Opcao invalida!!\n\n");
				break;
			}
			break;
		case 2:
			switch (op2){
				case 1:
					printf("Voce nao pode se alistar\n\n");
					break;
				case 2:
					printf("Parabens, voce pode se alistar\n\n");
					break;
				default:
					printf("Opcao invalida!!\n\n");
				break;
			}
			break;
		default:
			printf("Opcao invalida!!\n\n");
			
	}
		
	system("pause");
	return 0;
	
}