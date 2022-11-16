#include <stdio.h>
#include <stdlib.h>

struct lista
{
	int valor;
	struct lista *prox;
}typedef t_lista;

t_lista *criarnocabeca();
void copiarvetor();
int showlista();

int main()
{
	t_lista *cabecalista=NULL;
	cabecalista = criarnocabeca();
	copiarvetor (cabecalista);
	showlista(cabecalista);
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

void copiarvetor(t_lista *cabecalista){
	t_lista *ptrlista=NULL, *novono=NULL;
	int pos, i;
	printf("DIGITE O NUMERO DE POSICOES DO VETOR: ");
	scanf("%d", &pos);
	int vetor[pos];

	printf("PREENCHA O VETOR\n");
	for(i=0; i< pos; i++){
		printf("POSICAO %d: ", i);
		scanf("%d", &vetor[i]);
	}
	for(i=0; i< pos; i++){
		ptrlista = cabecalista;
		novono = malloc(sizeof(t_lista));
		novono->valor = vetor[i];
		novono->prox = NULL;
		while(ptrlista->prox != NULL){
			ptrlista = ptrlista->prox;
		}
		ptrlista->prox = novono;
	}
	printf("LISTA PREENCHIDA!\n");
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
