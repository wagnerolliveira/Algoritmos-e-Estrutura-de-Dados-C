#include <stdio.h>
#include <stdlib.h>
int main()
{
	int dinheiro,pais;
	printf ("o aluno possui dinheiro para a viagem? 1 - true 2 - false\n");
	scanf ("%d",&dinheiro);
	printf ("o aluno possui autorizacao dos pais para viajar? 3 - true 4 - false\n");
	scanf ("%d",&pais);
	if (dinheiro==1 && pais==3 ){
	    printf ("o aluno podera ir ao FEPEG!");
	}else{
	    printf ("o aluno nao ira ao FEPEG.");
	}
	system ("pause");
	return 0;
}
