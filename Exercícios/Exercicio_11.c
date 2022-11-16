#include<stdio.h>
#include<stdlib.h>

int main()

{
	float a, b, c, maior, meio, menor;
	printf ("Digite 3 numeros quisquer\n");
	scanf("%f %f %f", &a, &b, &c);
	if (a<b && a<c){
		menor=a;
		if (b<c){
			meio=b;
			maior=c;
		}else {
			meio=c;
			maior=b;
		}
	}else if (b<a && b<c){
		menor=b;
		if (a<c){
			meio=a;
			maior=c;
		}else {
			meio=c;
			maior=a;
		}
	}else if (c<a && c<b){
		menor=c;
		if (a<b){
			meio=a;
			maior=b;
		}else {
			meio=b;
			maior=a;
		}
	}else if (a==b){
		if (b<c){
			menor=a;
			meio=b;
			maior=c;
		}else {
			menor=c;
			meio=b;
			maior=a;
		}
	}else if (b==c){
		if (c<a){
			menor=b;
			meio=c;
			maior=a;
		}else {
			menor=a;
			meio=b;
			maior=c;
		}
	}else if (a==c){
		if (c<b){
			menor=a;
			meio=c;
			maior=b;
		}else {
			menor=b;
			meio=c;
			maior=a;
		}
	}else {
		menor=a;
		meio=b;
		maior=c;
	}
	printf ("A ordem crescente e %.3f %.3f %.3f\n\n", menor, meio, maior);
	system("pause");
	return 0;
}