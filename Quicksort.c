#include<stdio.h>

int partition(int *vet,int inicio,int fim)
{
  int esq,dir,pivo,aux;

  esq = inicio;
  dir = fim;
  pivo = vet[inicio];

  while(esq < dir)
    {
      while(esq <= fim && vet[esq] <= pivo)
	{
	  esq++;
	}
      while(dir >= 0 && vet[dir] > pivo)
	{
	  dir--;
	}
      if(esq < dir)
	{
	  aux = vet[esq];
	  vet[esq] = vet[dir];
	  vet[dir] = aux;
	}
    }
  vet[inicio] = vet[dir];
  vet[dir] = pivo;
  return dir;
}

void quicksort(int *vet,int inicio,int fim)
{
  int pivo;

  if(fim > inicio)
    {
      pivo = partition(vet,inicio,fim);
      quicksort(vet,inicio,pivo-1);
      quicksort(vet,pivo+1,fim);
    }
}

int main()
{
  int i;
  int vet[10] = {15,90,23,7,21,3,47,24,5,13};

  quicksort(vet,0,9);

  for(i=0;i<10;i++)
    {
      printf("%d\n",vet[i]);
    }
  return 0;
}
