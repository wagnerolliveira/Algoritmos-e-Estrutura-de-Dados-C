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

int contadordeno(arv* a)
{
	if(a == NULL){
        return 0;
	}else{
        return 1 + contadordeno(a->esq) + contadordeno(a->dir);
	}	
}

int contarFolhas(arv *a){
   if(a == NULL)
        return 0;
   if(a->esq == NULL && a->dir == NULL)
        return 1;
   return contarFolhas(a->esq) + contarFolhas(a->dir);
}


int maior(int a, int b){
    if(a > b)
        return a;
    else
        return b;
}

int altura(arv *a){
   if((a == NULL) || (a->esq == NULL && a->dir == NULL))
       return 0;
   else
       return 1 + maior(altura(a->esq), altura(a->dir));
}

int arv_imprime(arv* a)
{
	if (a!=NULL){
		printf("%d\t\t%d\n",a->chave,a->info); //Mostra raiz
		arv_imprime(a->esq);  //Mostra sae
		arv_imprime(a->dir);  //Mostra dir
	}
	return 0;
}


int main()
{
	int op;
	arv *arvore = NULL;
	printf("Insira a chave e o valor a ser inserido:\n");
	arvore = insere(arvore);
	do {
		printf("Insira a chave e o valor a ser inserido:\n");
		insere (arvore);
		printf("Deseja adicionar mais uma chave?\n");
		printf("1-SIM\n2-NAO\n");
		scanf("%d", &op);
	}while(op != 2);
	printf("\nCHAVE\t\tVALOR\n");
	arv_imprime(arvore);
	printf("\nO numero de nos da arvore e: %d\n", contadordeno(arvore));
	printf("O numero de nos nao folhas da arvore e: %d\n", contadordeno(arvore) - contarFolhas(arvore));
	printf("O numero de folhas da arvore e: %d\n", contarFolhas(arvore));
	printf("A altura da arvore e: %d\n\n", altura(arvore));
	return(0);
}
