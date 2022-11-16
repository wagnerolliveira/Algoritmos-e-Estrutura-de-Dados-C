#include<stdio.h>
#include<stdlib.h>
int main()
{
	int num1,i,resul;
	printf("digite um numero que te direi a sua tabuada:\n");
	scanf("%d",&num1);
	i = 1;
	resul = num1 *i;
	while (i<=10){
	    resul = num1 *i;
	    printf("\n%d * %d = %d\n ",num1,i,resul);
	    i++;
	}
	system ("pause");
	return 0;
}
