#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

struct lista{
	int valor;
	struct  lista *prox;
}typedef t_lista;

int inputval();
int verificar_lista();
t_lista *criar_lista();
int main (){
	int op;
	t_lista *lista_1=NULL, *lista_2=NULL;
	lista_1=criar_lista();
	lista_2=criar_lista();
	do{
		printf("================ MENU ================\n");
		printf("1- VERIFICAR NUMERO\n");
		printf("2- INSERIR NOVO ELEMENTO\n");
		printf("3- REMOVER ELEMENTO\n");
		printf("4- IMPRIMIR LISTA\n");
		printf("5- COPIAR LISTA\n");
		printf("6- CONCATENAR LISTA\n");
		printf("7- TAMANHO DA LISTA\n");
		printf("8- ENCERRAR PROGRAMA\n");
		printf("DIGITE A OPCAO DESEJADA: ");
		scanf("%d", &op);
		
		switch(op)
		{
		case 1:
			verificar_lista(lista_1, lista_2);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		default:
			break;
		}
	}while(op != 8);
	return 0;
}

t_lista *criar_lista(){
	t_lista *novalista = NULL;
	novalista = malloc(sizeof(t_lista));
	if(novalista == NULL){
		printf("MEMORIA NAO ALOCADA!\n");
		exit(1);
	}
	novalista->valor = 0;
	novalista->prox = novalista;
	return (novalista);
}

int inserir(t_lista *lista){
	t_lista *novo_no = NULL;
	t_lista *ptrlista = NULL;
	int quant;

	system("cls");
	printf("QUANTOS VALORES QUER INSERIR? ");
	scanf("%d", &quant);
	while(quant > 0){
		ptrlista = cabeca_lista;
		novo_no = malloc(sizeof(t_lista));
		printf("DIGITE O VALOR: ");
		scanf("%d", &novo_no->valor);
		novo_no->prox = NULL;

		while(ptrlista->prox != cabeca_lista){
			ptrlista = ptrlista->prox;
		}
		ptrlista->prox = novo_no;
		quant--;
	}
	ptrlista = NULL;
	return 0;
}

int verificar_lista(t_lista *lista_1, t_lista *lista_2 ){
	t_lista *ptrlista_1=NULL, *ptrlista_2=NULL;
	int list, num,i=0, tamanho=0;
	ptrlista_1 = ptrlista_1->prox;
	ptrlista_2 = ptrlista_2->prox;
	system("cls");
	printf("1- LISTA 1\n");
	printf("2- LISTA 2\n");
	printf("QUAL LISTA DESEJA VERIFICAR? ");
	scanf("%d", &list);
	do{
		if (num==1){
			printf("QUAL O NUMERO QUE DESEJA VERIFICAR? ");
			scanf("%d", &num);
			tamanho = tamanho_lista (lista_1);
			if (tamanho !=0){
				while (ptrlista_1!=lista_1){
					
					if(lista_1->valor==num){
						printf("Este número pertence a lista e esta presente na posição %d\n", i);
						i++;
					}
				}
				if (i==0){
						printf("Este número nao pertence a lista\n");
				}
				return 0;
			}else{
				printf("LISTA VAZIA\n");
				return 0;
			}	
		}else if(num==2){
			printf("QUAL O NUMERO QUE DESEJA VERIFICAR? ");
			scanf("%d", &num);
			if (tamanho_lista(lista_2)!=0){
				ptrlista_1= ptrlista_1->prox;
				while (ptrlista_2 != lista_2){
					if(lista_2->valor==num){
						printf("Este número pertence a lista e esta presente na posição %d\n", i);
						i++;
					}
					if (i==0){
						printf("Este número nao pertence a lista\n");
					}	
				}
				return 0;
			}else{
				printf("LISTA VAZIA\n");
				return 0;
			}
		}
	}while (list==1 || list==2);
	return 0;
}
int tamanho_lista(t_lista *lista){
	if (lista->prox==lista){
		return 0;
	}else {
		return 1+ tamanho_lista(lista->prox);
	}

}

