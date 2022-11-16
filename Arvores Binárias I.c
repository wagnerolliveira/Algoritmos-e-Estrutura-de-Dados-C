#include<stdio.h>
#include<stdlib.h>

struct cel {
	int chave;
	int info;
	struct cel *esq;
	struct cel *dir;
};

typedef struct cel no;
typedef no arv;

arv* arv_criavazia()
{
	return NULL;
}
arv* criar_arv(int chave, int info)
{
	arv* p = malloc(sizeof(arv));
	p->chave = chave;
	p->info = info;
	p->esq = arv_criavazia();
	p->dir = arv_criavazia();
	return p;
}


no* busca(arv *r, int k)
{
	if (r-> dir == NULL||r->esq == NULL || r->chave == k){
		printf("%d\t\t%d\n", r->chave, r->info);
		if (r->chave == k){
			printf("O Valor da chave inserida e: %d\n\n", r->info);
		}else {
			printf("Essa chave nao existe\n\n");
		}	
	  	return r;
	}if (r->chave > k){
		printf("%d\t\t%d\n", r->chave, r->info);
	  	return busca(r->esq,k);
	}else{
		printf("%d\t\t%d\n", r->chave, r->info);
		return busca(r->dir,k);
	}
}

no* insere(arv *r){
	no *f, *p, *novo;
	int chave, info;
	scanf("%d",&chave);
	scanf("%d",&info);
	novo= criar_arv(chave, info);
	if(r == NULL){
		return novo;
	}
	f = r;
	
	while(f != NULL){
		p = f;
		if (f->chave > novo->chave){
			f = f->esq;
		}else{
			f = f->dir;
		}
	}
	if (p->chave > novo->chave){
	  	p->esq = novo;
	}else{
		p->dir = novo;
	}
	return r;
}

int main()
{
	int chavebusca, op;
	arv *arvore = NULL;
	printf("Insira a chave e o valor a ser inserido:\n");
	arvore = insere(arvore);
	do {
		printf("Insira a chave e o valor a ser inserido:\n");
		insere (arvore);
		printf("Deseja adicionar mais uma chave? s/n \n");
		printf("1-SIM\n2-NAO\n");
		scanf("%d", &op);
	}while(op != 2);
	printf("Digite a chave que deseja buscar\n");
	scanf("%d",&chavebusca);
	printf("CHAVE\t\tVALOR\n");
	busca(arvore, chavebusca);
	return(0);
}
