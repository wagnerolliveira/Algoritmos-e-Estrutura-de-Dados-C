#include <stdlib.h>
#include <stdio.h>

int main()
{
	int num=2, i, contator_divisores=0, soma =0;
	for(num=2; num<=100; num++){
		for (i=1; i<=num; i ++){
			if (num%i==0){
				contator_divisores ++;
			}
		}
		if (contator_divisores==2){
			printf("%d\n ", num);
			soma+=num;
		}
		contator_divisores=0;
		i=1;
	}
	printf("A soma de todos os numeros primos de 1 a 100 e %d\n", soma);
	system ("pause");
	return 0;
}



