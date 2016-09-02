#include<stdio.h>
#include<string.h>
#define MAX 1010

int matriz[MAX][MAX],matrix[MAX][MAX];
int cor[MAX],pai[MAX],temp_entr[MAX],temp_saida[MAX],arvrinha[MAX];
int ident,top_tempo,maior,saida;

void ja_passo(int u,int N)
{
    int v;
    cor[u] = 2;
    temp_entr[u] = top_tempo++;
    
    for(v=0;v<N;v++)
    {
        if(matriz[u][v] == 1 && cor[v] == 1)
        {
            matriz[v][u] = 0;
            matrix[u][v] = 0;
            pai[v] = u;
            ja_passo(v,N);
        }
    }
    
    cor[u] = 3;
    temp_saida[u] = top_tempo++;
    if(temp_saida[u] > saida)
    {
        saida = temp_saida[u];
        maior = u;
    }
}

void ja_passou_volta(int u,int N)
{
    int v;
    
    arvrinha[u] = ident;
    cor[u] = 2;
    temp_entr[u] = top_tempo++;
    
    for(v=0;v<N;v++)
    {
        if(matrix[u][v] == 1 && cor[v] == 1)
        {
            pai[v] = u;
            ja_passou_volta(v,N);
        }
    }
    
    cor[u] = 3;
    temp_saida[u] = top_tempo++;
}

void profundidade(int N)
{
    int i;
    for(i=0;i<N;i++)
    {
        cor[i] = 1;
        pai[i] = -1;
    }
    
    saida = 0;
    top_tempo = 0;

    for(i=0;i<N;i++)
    {
        if(cor[i] == 1)
            ja_passo(i,N);
    }
}

void profundidade_volta(int N)
{
    int i;
    for(i=0;i<N;i++)
    {
        cor[i] = 1;
        pai[i] = -1;
    }
    
    top_tempo = 0;
    ident = 1;

    arvrinha[maior] = ident;
    ja_passou_volta(maior,N);
    
    for(i=0;i<N;i++)
    {
        if(cor[i] == 1)
        {
            ident++;
            ja_passou_volta(i,N);
        }
    }
}

int main()
{
    int N,M,A,B,i,j;
    
    while(scanf("%d %d",&N,&M) && N != 0 && M != 0)
{
        for(i=0;i<N;i++)
            for(j=0;j<N;j++)
            {
                matriz[i][j] = 0;
                matrix[i][j] = 0;
            }
        
        for(i=0;i<M;i++)
        {
            scanf("%d %d",&A,&B);
            matriz[A-1][B-1] = 1;//gravacao cruzada
            matriz[B-1][A-1] = 1;
            matrix[A-1][B-1] = 1;
            matrix[B-1][A-1] = 1;
        }

        profundidade(N);
        profundidade_volta(N);
        if(ident == 1)
            printf("S\n");
        else
            printf("N\n"); 
    }
    return 0;
}



