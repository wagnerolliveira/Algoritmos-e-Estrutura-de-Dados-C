#include<stdio.h>

int somatorio_interativo(int x, int y)
{
  int soma = 0;

  while(y>=x)
  {
  	  soma = soma + y;
  	  y--;
  }
  return(soma);
}

int somatorio_recursivo(int x, int y)
{
  if(x==y)
    {
      return(x);
    }
  else
    {
      return(y+somatorio_recursivo(x,y-1)); 
      
    }  
}
  
int main()
{
  int x,y;
  int soma_interativo;

  int soma_recursivo;

  printf("Digite a o primeiro numero: ");
  scanf("%d",&x);

  printf("Digite o segundo numero: ");
  scanf("%d",&y);
  
  
  soma_interativo = somatorio_interativo(x,y);
  soma_recursivo = somatorio_recursivo(x,y);

  printf("O somatorio e: %d\n",soma_interativo);
  printf("O somatorio e: %d\n",soma_recursivo);

  
  return(0);
}