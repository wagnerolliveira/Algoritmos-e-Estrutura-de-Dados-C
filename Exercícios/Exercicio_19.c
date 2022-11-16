#include<stdio.h>
#include<stdlib.h>

int main()

{
	int num, soma=0, num_par=0;
	float media=0;
	printf("Digite os valores para ver a media entre eles\\n\n");
	do {
		scanf("%d", &num);
		if (num !=0 && num % 2 ==0){
			soma += num; 
			num_par ++;
		}
	}while (num != 0);
	if (num_par != 0){
		media= soma / num_par;
	}else
	{
		media =0;
	}
	printf ("A media dos numeros e %.2f\n\n", media);
	system("pause");
	return 0;
}