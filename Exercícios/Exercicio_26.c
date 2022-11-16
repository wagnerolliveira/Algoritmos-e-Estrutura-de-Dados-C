#include <stdio.h>
#include <stdlib.h>
int main()

{

	int num,i=0,num_divisores;
	printf ("\ndigite um numero: ");
	scanf ("%d",&num);
	num_divisores = 0;
	for (i=1;i<=num;i++){
	    if((num%i)==0){
	    	printf("\no numero e divisivel por %d:",i);
	    	num_divisores++;
		}
	}
	if (num_divisores==2){
		printf("\no numero e primo");
	}else{
	  printf("\no numero n eh primo");
	}
	system("pause");
	return 0;
}

