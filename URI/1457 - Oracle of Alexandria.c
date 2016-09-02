#include <stdio.h>
#include <string.h>

long long int fatorial_loko(int n, int k)
{
	long long int resposta = 1;
	if((n - k) < 1)
		resposta = n;
	else
		resposta = n * fatorial_loko(n - k, k);
	return resposta;
}
	
int main()
{
	int num,a,k;
	scanf("%d", &num);
	for(a=0;a<num;a++)
	{
		char linha[25];
		scanf("%s", linha);
		int i = 0;
		while(linha[i] != '!')
			i++;
		char numero[i];
		for(k = 0; k < i; k++){
				numero[k] = linha[k];
		}
		int k = strlen(linha) - i;
		int n;
		if(i == 1)
			n = numero[0] - 48;
		else if(i == 2)
			n = (numero[0] - 48) * 10 + (numero[1] - 48);
		else
			n = 100;
		printf("%lld\n", fatorial_loko(n, k));
	}
	return 0;
}


