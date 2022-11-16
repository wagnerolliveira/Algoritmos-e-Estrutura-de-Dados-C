#include<stdio.h>
#include<stdlib.h>

struct funcionario{
	int cod;
	char nome[30];
	char setor[30];
}typedef t_func;

struct lista {
	struct lista *ant;
	int valor;
	struct lista *prox;
}typedef t_lista;


t_lista *criar_lista();

int liberar_lista(t_lista *cabecalista);

t_lista *inserir_inicio(t_lista *cabecalista, int valor);

int inserir_meio(t_lista *cabecalista, int pos, int valor);

int inserir_fim(t_lista *cabecalista, int valor);

//int inserir_ordenado(t_lista *cabecalista, int valor);

int contar_nos(t_lista *cabecalista);

int removerno(t_lista *cabecalista, int valor);


int show_lista(t_lista *cabecalista);

int main()
{
  t_lista *cabecalista=NULL;
  
  cabecalista = criar_lista();

  cabecalista->prox = inserir_inicio(cabecalista, 1);
  cabecalista->prox = inserir_inicio(cabecalista,2);

  inserir_fim(cabecalista,3);

  show_lista(cabecalista);

  contar_nos(cabecalista);

  inserir_meio(cabecalista,2,27);

  show_lista(cabecalista);

  removerno(cabecalista,1);

  show_lista(cabecalista);
  
  contar_nos(cabecalista);
  
  liberar_lista(cabecalista);
  
  return 0;
}

t_lista *criar_lista()
{
  t_lista *ptrlista = malloc(sizeof(t_lista));

  if(ptrlista != NULL)
    {
      ptrlista->prox = NULL;
      ptrlista->ant = NULL;   
    }
  return ptrlista;
}

int liberar_lista(t_lista *cabecalista)
{
  t_lista *ptrlista=cabecalista->prox;
  t_lista *atual=NULL;
  
  if(ptrlista == NULL)
    {
      printf("\n\nLista vazia!\n\n");
      return 1;
    }
  else
    {
      while(ptrlista != NULL)
	{
	  atual = ptrlista;
	  ptrlista = ptrlista->prox;
	  free(atual);
	}
      free(ptrlista);
      printf("\n\nLista vazia!\n\n");
    }
  return 0;
}

t_lista *inserir_inicio(t_lista *cabecalista, int valor)
{
  t_lista *ptrlista = cabecalista->prox;
  t_lista *novono = malloc(sizeof(t_lista));

  if (novono != NULL)
    {
      if(ptrlista != NULL)
	{
	  novono->valor = valor;
	  novono->ant = NULL;
	  novono->prox = ptrlista;
	  ptrlista->ant = novono;
	}
      else
	{
	  novono->valor = valor;
	  novono->ant = NULL;
	  novono->prox = NULL;
	}
      return novono;
    }
  else
    {
      printf("Memoria nao alocada!");
      return NULL;
    }
}

int inserir_meio(t_lista *cabecalista, int pos, int valor)
{
	int inserido = 1;
	int posatual = 0;
	
	t_lista *ptratual = NULL;
	
	t_lista *ptrlista = cabecalista->prox;
	
	t_lista *novono = malloc(sizeof(t_lista)); 
	
	if (novono != NULL){
		while (ptrlista != NULL && posatual < pos){
			posatual++;
			ptratual = ptrlista;
			ptrlista = ptrlista->prox;
		}
	
		if (ptrlista != NULL || posatual == pos){
			if (pos == 0){
				novono->valor = valor;
				novono->ant = NULL;
				novono->prox = cabecalista->prox;
				cabecalista->prox = novono;
			}	
			else{
				novono->valor = valor;
				novono->prox = ptratual->prox;
				novono->ant = ptratual;
				ptratual->prox = novono;
			}
		}else{
			printf("\n\nPosicao nao existe!\n\n");
			return 1;
		}
	}
	else{
		printf("\n\nErro!!\nMemoria nao alocada!");
		return 1;
	}
	return 0;
}

int inserir_fim(t_lista *cabecalista, int valor)
{
	t_lista *ptrlista = cabecalista->prox;
	
	t_lista *no_atual = ptrlista;
	
	t_lista *no_anterior = NULL;
	
	t_lista *novono = malloc(sizeof(t_lista));

	if (novono != NULL){
		while(no_atual != NULL){
	  	  no_anterior = no_atual;
	  	  no_atual = no_atual->prox;
		}
	
		novono->valor = valor;
		novono->ant = no_anterior;
		novono->prox = NULL;
	   	no_anterior->prox = novono;
	  
		return 0;
	}
	else{
		printf("\nERRO!\nMemoria nao alocada!\n");
		return 1;
	}
}

int contar_nos(t_lista *cabecalista)
{
	int cont = 0;
	t_lista *ptrlista = cabecalista->prox;
	
	while (ptrlista != NULL){
		cont++;
		ptrlista = ptrlista->prox;
	}

	printf("\n\nlista possui: %d nos.\n",cont);
	
	return 0;
}

int removerno(t_lista *cabecalista, int valor)
{

	t_lista *ptrlista = cabecalista->prox;
	t_lista *anterior = NULL;
	t_lista *antlast = NULL;
	t_lista *proximo = NULL;
	
	while (ptrlista != NULL && ptrlista->valor != valor){
		antlast = ptrlista;
		ptrlista = ptrlista->prox;
	}
	
	if (ptrlista == NULL){
		printf("\n\nValor %d nao esta na lista!\n\n",valor);
		return 1;
	}
	else{
		if(ptrlista->prox == NULL){
			antlast->prox=NULL;
			free(ptrlista);
			
		}else if (ptrlista->prox == NULL && ptrlista-> ant == NULL){
			cabecalista->prox=NULL;
			free(ptrlista);
		}else {
			if (ptrlista-> ant == NULL){
				proximo = ptrlista->prox;
				proximo->ant = ptrlista->ant;
				free(ptrlista);
			}else{
				anterior = ptrlista->ant;
				anterior->prox = ptrlista->prox;
				free(ptrlista);
			}
		}
	}
	return 0;
}

int show_lista(t_lista *cabecalista)
{
	t_lista *ptrlista = cabecalista->prox;
	int pos = 0;
	
	printf("\n  ");
	while(ptrlista != NULL){
		printf("\nvalor da posicao %d e %d", pos, ptrlista->valor);
		pos++;
		ptrlista = ptrlista->prox;
	}
	return 0;
}
  
      
