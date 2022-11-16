#include<stdio.h>
#include<stdlib.h>

int main()

{
	int a, b, i=0;
	printf("Digite o numero inicial\n");
	scanf("%d", &a);
	printf("Digite o numero final\n");
	scanf("%d", &b);
	if (b<a){
	 	for (i=a; i>=b; i--){
			printf ("%d ", i);
		}
	}else{
		for (i=a; i<=b; i++){
			printf("%d ", i);
		}
	}
	system("pause");
	return 0;
}