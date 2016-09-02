#include <stdio.h>

int comandos (int *v, int i, int *termo)
{
	int j,cont=0;
	
	for(j=i-1;j>=0;j--)
	{
		cont++;
		if(v[i]==v[j])
			return (cont);
	}
	*termo = 1;
	return (cont);
}
int main ()
{
	int cont,i,n,termo;
	while(scanf("%d", &n) && n!=0)
	{
		cont=0;
		int v[n];
		for(i=0;i<n;i++)
		{
			scanf("%d",&v[i]);
			termo=0;
			cont+=comandos(v,i,&termo);
			if(termo==1)
				cont+=v[i];
		}
		printf("%d\n",cont);
	}
	return 0;
}

