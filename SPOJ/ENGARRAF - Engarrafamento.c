#include <stdio.h>
#define INF 9999999 //pra gambiarra, mudar antes de mandar pro spoj
 
int matriz[101][101];
int n, m;

int melhor_caminho(int d, int s)
{
        int a,v,min;
        int custo[n+1],foise[n+1];//vetor dos q ja foram (foise)
        
        for (a = 1; a <(n+1); a++)
        {
            custo[a] = INF;
            foise[a] = 0;
        }
        
        v = s;
        custo[s] = 0;
        
        while (v!=d) 
        {  
            min = INF;
            foise[v] = 1;
            for (a=1;a<(n+1);a++)
                if (matriz[v][a]!= -1 && ((custo[v] + matriz[v][a]) < custo[a]))
                    custo[a] = matriz[v][a] + custo[v];

            for (a=1;a<(n+1);a++)
                if (foise[a]==0 &&  min>custo[a])
                {
                    min = custo[a];
                    v = a;
                }
            if (min >= INF) 
                return (-1);
        }
        return (custo[d]);
}
 
 
int main()
{  
    int a,b,i,j,k,s,d;
    while (scanf("%d %d", &n, &m)!=0 && n!=0 )
    {
        for(a=1; a<(n+1); a++)
            for(b=1; b<(n+1); b++)
                matriz[a][b]=-1;

        for (a=0; a<m; a++)
        {
            scanf("%d %d %d", &i, &j, &k);
            matriz[i][j]=k;
        }
        
        scanf("%d %d", &s, &d);
        printf("%d\n",melhor_caminho(d,s));

    }
    return 0;
} 

