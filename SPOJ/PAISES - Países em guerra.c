#include <stdio.h>
#define MAX 1000

int matriz[MAX][MAX], custo[MAX], lista[MAX];
//matriz de adjacencias e vetores

int melhor_caminho(int N, int O, int D)
{
        int u, i;
        for(i = 0; i <= N; i++)
        {
                custo[i] = MAX*MAX;
                lista[i] = 1;
        }
        custo[O] = 0;
        u = O;
        
        while(u != D)
        {
                for(i = 0; i < N; i++)
                        if(matriz[u][i] != MAX*MAX)
                                 if(matriz[u][i] + custo[u] < custo[i])
                                        custo[i] = matriz[u][i] + custo[u];
                        
                
                lista[u] = 0;
                int min = MAX*MAX;
                for(i = 0; i < N; i++)
                {
                        if(lista[i] == 1 && custo[i] < min)
                        {
                                min = custo[i];
                                u = i;
                        }  
                }
                
                if(min == MAX*MAX)
                        return MAX*MAX;
                
        }
        return custo[D];
}

int main()
{
        int N, E, X, Y, H, K, O, D, melhor, i, j;
        while(scanf("%d %d", &N, &E) == 2 && N)
        {
                for(i = 0; i < N; i++)
                        for(j = 0; j < N; j++)
                                matriz[i][j] = MAX*MAX;
                                
                for(i = 0; i < E; i++)
                {
                        scanf("%d %d %d", &X, &Y, &H);
                        matriz[X-1][Y-1] = H;
                        if(matriz[Y-1][X-1] != MAX*MAX)
                        {
                                matriz[X-1][Y-1] = 0;
                                matriz[Y-1][X-1] = 0;
                        }
                        
                }
                scanf("%d", &K);
                for(i = 0; i < K; i++)
                {
                        scanf("%d %d", &O, &D);
                        if(matriz[O-1][D-1] == 0)
                                melhor = 0;
                        else
                                melhor = melhor_caminho(N, O-1, D-1);
                        
                        if(melhor == MAX*MAX)
                                printf("Nao e possivel entregar a carta\n");
                        else
                                printf("%d\n", melhor); 
                }
                printf("\n");
        }
        return 0;
}

