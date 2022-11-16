#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main ()
{
	char nome_miss[60], vencedora[60];
	float nota_miss, nota_vencedora=0;
	int i;
	for (i=0; i<16; i++){
		printf("Nome da candidata\n");
		setbuf(stdin,NULL);
		gets(nome_miss);
		printf ("Nota da candidata\n");
		scanf("%f", &nota_miss);
		if (nota_miss>=0 && nota_miss<=10){
			if (nota_miss> nota_vencedora){
				strcpy(vencedora, nome_miss);
				nota_vencedora = nota_miss;
			}
		}else
		{
			printf("Nota invalida");
		}	
	}
	printf ("A vencedora foi %s com um total %.1f pontos\n\n", vencedora, nota_vencedora);
	system("pause");
	return 0;
}