#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int main ()
{
	int a,b,c,i;
	a = 0;
	b = 1;
	c = 0;
	i = 0;
	printf ("%d \n%d\n",a,b);
	
	while(i<18){
		c = a + b;
		Sleep(100);
		printf ("%d\n",c);
		a=b;
		b=c;
		i++;
	}
	
	system ("pause");
	return 0;
}
