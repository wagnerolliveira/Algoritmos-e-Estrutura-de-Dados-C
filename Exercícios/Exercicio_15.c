#include<stdio.h>
#include<stdlib.h>

int main()

{
	int i, resto=0;
	for (i=50; i<=100; i++){
		resto= i%2;
		if (resto==1){
			printf("%d \n", i);
		}
	}
	system("pause");
	return 0;
}