#include <stdio.h>
#include <math.h>
#define MAX 100000
#define MOD 1300031

long long int mod (long long int x)
{
	return(((x%MOD)+MOD)%MOD);
}

int main ()
{
	long long int t,a,i,n;
	long long int vetor[MAX];
	scanf("%lld",&t);
	for(a=0;a<t;a++)
	{
		scanf("%lld",&n);
		long long int somap=0,somat=0; //soma parcial / soma total
		
		for (i=0;i<n;i++)
		{
			scanf("%lld",&vetor[i]);
			somap += vetor[i];
		}
		
		for (i=0;i<n;i++)
		{
			somat = mod(somat+mod(mod(somap)*vetor[i]));
			somap -= vetor[i];
		}
		printf("%lld\n",somat);
	}
	return (0);
}
