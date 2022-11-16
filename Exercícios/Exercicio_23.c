#include<stdio.h>
#include<stdlib.h>

int main ()
{
	int x,i;
	printf("Informe o numero para achar o fatorial dele\n\n");;
	scanf("%d",&x);
	if (x>0){
		for (i=1; x>=1; x--){
			i=i*x;
		}
	}else{
		printf("ERRO");
	}
	printf("%d",i);
	system("pause");
	return 0;
}