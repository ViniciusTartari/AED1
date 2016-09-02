#include <stdio.h>
#include <math.h>

int hanoy (int n)
{
	int v;
	v = pow(2,n)-1;
	return(v);
}
int main ()
{
	int n,i,k=0;
	while(scanf("%d",&n) && n!=0)
	{
		k++;
		printf("Teste %d\n%d\n\n",k,hanoy(n));
	}
	return 0;
}
