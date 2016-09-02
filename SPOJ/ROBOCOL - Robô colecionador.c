#include <stdio.h>

int main()
{
	int n,m,s,orientacao=0,ox=0,oy=0,i,j,ax,ay,cont;
	while (scanf("%d %d %d ", &n, &m, &s) && (n || m || s))
	{
		char inst, matriz[n+1][m+1];
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
			{
				scanf("%c ", &matriz[i][j]);
				if (matriz[i][j] == 'N')
				{
					orientacao = 0;
					ox = i; 
					oy = j;
					matriz[i][j] = '.';
				}
				else if (matriz[i][j] == 'L')
				{
					orientacao = 1;
					ox = i; 
					oy = j;
					matriz[i][j] = '.';
				}
				else if (matriz[i][j] == 'S')
				{
					orientacao = 2;
					ox = i; 
					oy = j;
					matriz[i][j] = '.';
				}
				else if (matriz[i][j] == 'O')
				{
					orientacao = 3;
					ox = i; 
					oy = j;
					matriz[i][j] = '.';
				}
			}
		cont = 0;
		for (i = 0; i < s; i++)
		{
			scanf("%c ", &inst);
			ax = ox;
			ay = oy;
			if (inst == 'D')
				orientacao = (orientacao + 1) % 4;
			else if (inst=='E')
			{
				if (orientacao == 0)
					orientacao = 3;
				else
					orientacao -= 1;
			}
			else if(inst=='F')
			{
				if (orientacao == 0 && ox != 0)
					ox--;
				else if (orientacao == 1 && oy != m - 1)
					oy++;
				else if (orientacao == 2 && ox != n - 1)
					ox++;
				else if (orientacao == 3 && oy != 0)
					oy--;
				if (matriz[ox][oy] == '*')
				{
					cont++;
					matriz[ox][oy] = '.';
				}
				else if (matriz[ox][oy] == '#')
				{
					ox = ax;
					oy = ay;
				}
			}
		}
		printf("%d\n",cont);
	}
	return 0;
}
