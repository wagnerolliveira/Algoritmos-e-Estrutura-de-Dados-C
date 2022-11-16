#include<stdio.h>
#include<stdlib.h>

int main()

{
	float a, b, c, media=0;
	printf("Digite 3 numeros\n");
	scanf("%f %f %f", &a, &b, &c);
	media=(a+b+c)/3;
	printf("A media e %.2f \n\n", media);
	system("pause");
	return 0;
}
