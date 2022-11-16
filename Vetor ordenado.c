#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10000
int vetorordenado(int n, int v[])
{
    int i,j;
    int temp,count1=0, count2=0;

    for (i = n - 1; i >= 1; i--){
        for (j = 0; j < i; j++){
            if (v[j] > v[j+1]){
                temp = v[j]; //troca
                v[j] = v[j+1];
                v[j+1] = temp;
                count1++;
            }else{
                count2++;
            }
        }
    }
    printf("\nVetor ordenado: ");
    for (i = 0; i < TAM; i++){
        printf(" %d;",v[i]);
    }
    printf("\nTrocas feitas: %d\n", count1);
    printf("Verificacoes sem trocas: %d\n", count2);
    return 0;
}
int vetorinverso(int n, int v[]){
    int i,j;
    int temp,count1=0,count2=0;

    for (i = n - 1; i >= 1; i--){
        for (j = 0; j < i; j++){
            if (v[j] < v[j+1]){
                temp = v[j]; //troca
                v[j] = v[j+1];
                v[j+1] = temp;
                count1++;
            }else {
                count2++;
            }
        }
    }
    printf("\nVetor inverso: ");
    for (i = 0; i < TAM; i++){
        printf(" %d;",v[i]);
    }
    printf("\nTrocas feitas: %d\n", count1);
    printf("Verificacoes sem trocas: %d\n", count2);
    return 0;
}

int main()
{
    int vet[TAM],t1,t2,t3,i;
    t1=clock();
    for (i=0; i<TAM; i++){
        vet[i]= rand() % 10000;
    }
    printf("Vetor aleatorio: ");
    for (i = 0; i < TAM; i++){
        printf(" %d;",vet[i]);
    }
    t1=clock()-t1;
    printf("\nTempo de execucao: %lf\n", ((double)t1)/((CLOCKS_PER_SEC/1000)));
    t2=clock();
    vetorordenado(TAM,vet);
    t2=clock()-t2;
    printf("Tempo de execucao: %lf\n", ((double)t2)/((CLOCKS_PER_SEC/1000)));
    t3=clock();
    vetorinverso(TAM,vet);
    t3=clock()-t3;
    printf("Tempo de execucao: %lf\n", ((double)t3)/((CLOCKS_PER_SEC/1000)));

    return 0;
}
