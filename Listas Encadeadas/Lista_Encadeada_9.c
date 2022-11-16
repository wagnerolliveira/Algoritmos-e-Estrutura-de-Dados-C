#include <stdio.h>
#include <stdlib.h>

struct lista
{
	int valor;
	struct lista *prox;
}typedef t_lista;

t_lista *criarnocabeca();
int inserirno();
int contadordeno();
int copiarlista();

int main()
{
	t_lista *cabecalista=NULL;
	cabecalista = criarnocabeca();
	inserirno (cabecalista);
	copiarlista(cabecalista);
	return 0;
}


t_lista *criarnocabeca()
{
	t_lista *novalista=NULL;
	
	novalista = malloc(sizeof(t_lista));
	
	if(novalista == NULL)
	{
	  printf("\nA memoria nao pode ser alocada!\n\n");
	  exit (1);
	}
	
	novalista->valor=0;
	novalista->prox = NULL;
	
	return novalista;
}

int inserirno(t_lista *cabecalista)
{
	t_lista *ptrlista1=NULL;
	t_lista *ptrlista2=NULL;
	t_lista *novono=NULL;
	
	int op=0;
	
	
	do{
		ptrlista1 = cabecalista->prox;
		ptrlista2 = cabecalista->prox;
		
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
			cabecalista->prox = ptrlista1;
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
int contadordeno(t_lista *cabecalista){
	if(cabecalista->prox == NULL){
		return 0;
	}
	
	else{
		return 1+(contadordeno(cabecalista->prox));
	}	
}
	
int copiarlista(t_lista *cabecalista){
	t_lista *ptrlista = NULL;
	int pos ;
	pos = contadordeno(cabecalista);
	int vetor[pos];
	int i = 0;
	if(cabecalista->prox == NULL){
		printf("LISTA VAZIA\n");
		return 0;
	}
	else{
		ptrlista = cabecalista->prox;
		while(ptrlista != NULL){
			vetor[i] = ptrlista -> valor;
			ptrlista = ptrlista->prox;
			i++;
		}
	}
	for(i = 0; i < pos; i++){
		printf("[ %d ] ", vetor[i]);
	}
	return 0;
}
