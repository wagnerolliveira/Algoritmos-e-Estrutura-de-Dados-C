#include<stdio.h>
#include<stdlib.h>

int main()

{
	char sexo;
	do {
		printf("Qual o seu sexo?\n");
		setbuf(stdin,NULL);
		scanf ("%c", &sexo);
	}while (sexo != 'm' && sexo != 'f');
	if (sexo == 'm'){
		printf("Masculino\n");
	}else{
		printf("Feminino\n");
	}
	system("pause");
	return 0; 
}