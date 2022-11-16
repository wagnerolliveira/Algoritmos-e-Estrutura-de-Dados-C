#include <stdio.h>
#include <stdlib.h>
int main ()
{
	int num1,num2,num3;
	printf("digite 3 numeros:\n");
	scanf ("%d %d %d",&num1,&num2,&num3);
	
	if (num1 == num2 && num2 == num3){
	    printf ("Os tres valores sao iguais.\n");
	}else if (num1 != num2 && num2 != num3 && num1 !=num3){
		printf ("Nao ha valores iguais.\n");
	
	}else{
		printf ("Ha 2 valores iguais e um diferente.\n");
	}	
	system ("pause");
	return 0;
}
