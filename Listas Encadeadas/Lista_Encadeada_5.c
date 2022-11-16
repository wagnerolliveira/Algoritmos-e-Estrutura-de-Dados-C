#include <stdio.h>
#include <stdlib.h>

struct lista
{
	int valor;
	struct lista *prox;
}typedef t_lista;

t_lista *criarnocabeca();
int inserirno();
void verificarlista();
int verificarlistarecursivo();
int main()
{
	t_lista *cabecalista1=NULL;
	t_lista *cabecalista2=NULL;
	cabecalista1 = criarnocabeca();
	cabecalista2 = criarnocabeca();
	printf("CRIANDO LISTA 1...");
	inserirno (cabecalista1);
	printf("CRIANDO LISTA 2...");
	inserirno (cabecalista2);
	verificarlista(cabecalista1, cabecalista2);
	printf("===RECURSIVO===\n");
	if (verificarlistarecursivo(cabecalista1, cabecalista2)==0){
		printf("As listas sao iguais\n");
	}else{
		printf("As listas sao diferentes\n");
	}
	return 0;
}


t_lista *criarnocabeca()
{
	t_lista *novalista=NULL;
	novalista = malloc(sizeof(t_lista));
	if(novalista == NULL)
	{
	  printf("\n\nA memoria nao pode ser alocada!\n\n");
	  exit (1);
	}
	novalista->valor=0;
	novalista->prox = NULL;
	return novalista;
}

int inserirno(t_lista *cabecalista1)
{
	t_lista *ptrlista1=NULL;
	t_lista *ptrlista2=NULL;
	t_lista *novono=NULL;
	int op=0;	
	do{
		ptrlista1 = cabecalista1->prox;
		ptrlista2 = cabecalista1->prox;
		novono = malloc(sizeof(t_lista));
		printf("\nDigite o valor:");
		scanf("%d",&novono->valor);      
		novono->prox=NULL;
		while(ptrlista2 != NULL ){
			ptrlista1=ptrlista2;
			ptrlista2=ptrlista2->prox;
		}
		if(ptrlista1 == ptrlista2){
			novono->prox = ptrlista1;
			ptrlista1 = novono;
			cabecalista1->prox = ptrlista1;
		}
		else {
			novono->prox = ptrlista1->prox;
			ptrlista1->prox = novono;
		}    	
		printf("Digite 0 (zero) para continuar ou outro valor para sair: ");
		scanf("%d",&op);
		novono = NULL;
		ptrlista1 = NULL;
		ptrlista2 = NULL;
	
	}while (op == 0 );
	return 0;
}
void verificarlista(t_lista *cabecalista1, t_lista *cabecalista2){
	int pos=0;
	t_lista *ptrlista1=NULL;
	t_lista *ptrlista2=NULL;
	ptrlista1 = cabecalista1->prox;
	ptrlista2 = cabecalista2->prox;
	while(ptrlista1 != NULL && ptrlista2 != NULL){
		if(ptrlista1->valor != ptrlista2->valor){
			pos++;
		}
		ptrlista1 = ptrlista1 -> prox;
		ptrlista2 = ptrlista2 -> prox;
	}
	if(pos == 0 && ptrlista1 == NULL && ptrlista2 == NULL){
		printf("As listas sao iguais\n");
	}	
	else{
		printf("As listas sao diferentes\n");
	}	
}
int verificarlistarecursivo(t_lista *cabecalista1, t_lista *cabecalista2){
	if(cabecalista1 == NULL || cabecalista2 == NULL){
		if(cabecalista1 == cabecalista2){
			return 0;
		}	
		else{
			return 1;
		}	
	}
	else if(cabecalista1->valor != cabecalista2->valor){
		return 1;
	}
	else{
		return 0 + verificarlistarecursivo(cabecalista1->prox, cabecalista2->prox); 
	}
}