#include <stdio.h>
#include <stdlib.h>

struct lista
{
	int valor;
	struct lista *prox;
}typedef t_lista;

t_lista *criarnocabeca();
int inserirno();
int showlista();
int contadordeno();

int main()
{
	t_lista *cabecalista=NULL;
	cabecalista = criarnocabeca();
	inserirno (cabecalista);
	showlista(cabecalista);
	printf("\n\nHa %d celula(s) nessa lista",contadordeno(cabecalista));
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
		
		printf("\n\nDigite 0 (zero) para continuar ou outro valor para sair: ");
		scanf("%d",&op);
		
		novono = NULL;
		ptrlista1 = NULL;
		ptrlista2 = NULL;
	
	}while (op == 0 );
	
	return 0;
	}
	
int showlista(t_lista *cabecalista){
	t_lista *lista;
	int pos=0;
	
	if(cabecalista->prox == NULL){
		printf("\n\nLista vazia!\n\n");
	}
	
	else{
		lista = cabecalista;

		while(lista->prox!=NULL){
	    	
	    	lista=lista->prox;
	    	printf("\n\nO conteudo da posicao %d e %d\n",pos,lista->valor);
	    	pos++;
		}
	}	
	return(0);
}
int contadordeno(t_lista *cabecalista){
	if(cabecalista->prox == NULL){
		return 0;
	}
	
	else{
		return 1+(contadordeno(cabecalista->prox));
	}	
}