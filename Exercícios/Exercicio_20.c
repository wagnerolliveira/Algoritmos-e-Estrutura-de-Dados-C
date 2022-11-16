#include <stdio.h>
#include <stdlib.h>
int main()
{
	int num,maior,menor,i;
	i = 0;
	num = 0;
	maior = 0;
	menor = 0;
	printf ("\nDigite numeros e direi o maior e o menor deles,digite 0 para obter o resultado:\n");
	do{
	    scanf("%d",&num);
	    if (i== 0){
	        maior = num;
	        menor = num;
	        i++;
	    }else if(num==0){
			break;
		}else if (num > maior){
		    maior = num;
	    }else if(num<menor){
			menor = num;
		}  
	
	}while (1);
	printf ("\nmaior numero : %d\nmenor numero: %d",maior,menor);
	return 0;
	system("pause");
}

