#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#define TAM 100000
int main()
{
    int vet1[TAM], vet2[TAM],t1,t2,i;
    t1=clock();
    for (i=0; i<TAM; i++){
        vet1[i]= rand() % 19999;
        vet2[i]=vet1[i];
    }
    t1=clock();
    bolha(TAM,vet1);
    for(i=0;i<TAM;i++){
        printf("[%d]",vet1[i]);
    }
    t1=clock()-t1;
    printf("\n\n");
    t2=clock();
    quicksort(vet2,0,TAM -1);
    for(i=0;i<TAM;i++){
        printf("[%d]",vet2[i]);
    }
    t2=clock()-t2;
    printf("\nTempo de execucao Bubble Sort: %lf\n", ((double)t1)/((CLOCKS_PER_SEC/1000)));
    printf("Tempo de execucao Quicksort.: %lf\n", ((double)t2)/((CLOCKS_PER_SEC/1000)));
}
