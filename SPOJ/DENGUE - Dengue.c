#include <stdio.h>
#define MAX 100

int matriz[MAX][MAX], lista[MAX], custo[MAX], customax[MAX];

int dikistra(int v_inicio, int n)
{
        int i, min, u = v_inicio;;
        for(i = 0; i < n; i++)
        {
            lista[i] = 1;
            custo[i] = MAX*MAX;
        }
        custo[v_inicio] = 0;
        while(u != -1)
        {
                lista[u] = 0;
                for(i = 0; i < n; i++)
                        if(matriz[u][i] && lista[i] && custo[u] + matriz[u][i] < custo[i])
                                custo[i] = custo[u] + matriz[u][i];
                                
                                
                min = MAX*MAX;
                for(i = 0; i < n; i++)
                        if(lista[i] && custo[i] < min)
                                min = custo[i], u = i; 
                                
                if(min == MAX*MAX)
                        u = -1;
        }
        
        min = 0;
        for(i = 0; i < n; i++)
                if(custo[i] > min)
                        min = custo[i];
                        
        customax[v_inicio] = min;
}

int main()
{
        int n, i, cont = 1;
        while(scanf("%d", &n) && n!=0)
        {
                int j,u,v,menor = 0;
                for(i = 0; i < n; i++)
                {
                        customax[i] = MAX*MAX;
                        for(j = 0; j < n; j++)
                                matriz[i][j] = 0;
                }
                for(i = 1; i < n; i++)
                {
                        scanf("%d %d", &u, &v);
                        u--;
                        v--;
                        matriz[u][v] = 1;
                        matriz[v][u] = 1;
                }
                for(i = 0; i < n; i++)
                {
                        dikistra(i,n);
                        if(customax[i] < customax[menor])
                                menor = i;
                }
                printf("Teste %d\n%d\n\n", cont++, menor+1);
                
        }
        return 0;
}

