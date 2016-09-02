#include <stdio.h>
#define MAX 1000
  
int g[MAX][MAX+1]; //matriz mais uma coluna de cont
int n, k;
  
void eliminadora(int x)
{
    int i;
    g[x][n] = 0;
      
    for(i = 0; i < n; i++)
    {
        if(g[x][i])
        {
            g[x][i] = 0;
            g[i][x] = 0;
            g[i][n]--;
            if(g[i][n] > 0 && g[i][n] < k)
                eliminadora(i);
        }
    }
}
  
int main()
{
    int m;
    while(scanf("%d %d %d", &n, &m, &k) == 3)
    {
        int i,j;
  
        if(k > 0)
            for(i = 0; i < n; i++)
                for(j = 0; j <= n; j++)
                    g[i][j] = 0;
  
        for(i = 0; i < m; i++)
        {
            int a,b;
            scanf("%d %d", &a, &b);
            g[a-1][n]++;
            g[b-1][n]++;
            g[a-1][b-1] = 1;
            g[b-1][a-1] = 1;
        }
         
        if(k == 0)
        {
            printf("1");
            for(i = 1; i < n; i++)
                printf(" %d", i+1);
        }
        else
        {
     
            for(i = 0; i < n; i++)
                if(g[i][n] < k && g[i][n] > 0)
                    eliminadora(i);
                     
            int verif = 0;
            for(i = 0; i < n; i++)
                if(g[i][n] >= k)
                {
                    if(!verif)
                    {
                        verif = 1;
                        printf("%d", i+1);
                    }
                    else
                        printf(" %d", i+1);
                }
     
     
            if(!verif)
                printf("0");
        }
        printf("\n");
    }
  
    return 0;
}
