#include<stdio.h>
#include<stdlib.h>

int main ()
{
	int matriz[5][5]={{1,0,0,0,0},{0,1,0,0,0},{0,0,1,0,0},{0,0,0,1,0},{0,0,0,0,1}}, i, j;
	for (i=0; i<5;i++){
		printf("\n");
		for (j=0; j<5; j++){
			printf("%d  ", matriz[i][j]);
		}
	}
	return 0;
}