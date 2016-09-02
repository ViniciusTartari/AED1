#include<stdio.h>
#define MAX 7

int matriz[MAX][MAX]; //matriz do grafo
int cor[MAX],pai[MAX],temp_entr[MAX],temp_saida[MAX],arvrinha[MAX],cont[MAX]; //vetores controladores
int ident,top_tempo,maior,saida;

void ja_passo(int u,int N)
{
    int v;
    cor[u] = 2;
    temp_entr[u] = top_tempo++;
    
    for(v=0;v<N;v++)
    {
        if(matriz[u][v] == 1 && cor[v] == 1 && cont[v] != 0)
        {
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

void profundidade(int N)
{
    int v;
    for(v=0;v<N;v++)
    {
        cor[v] = 1;
        pai[v] = -1;
    }
    
    top_tempo = 0;
    saida = 0;

    for(v=0;v<N;v++)
    {
        if(cor[v] == 1 && cont[v] != 0)
            ja_passo(v,N);
    }
}

void ja_passo_volta(int u,int N)
{
    int v;
    
    arvrinha[u] = ident;//marca a arvrinha (kkk) a qual o vertive pertence
    cor[u] = 2;
    temp_entr[u] = top_tempo++;
    
    for(v=0;v<N;v++)
    {
        if(matriz[u][v] == 1 && cor[v] == 1 && cont[v] != 0)
        {
            pai[v] = u;
            ja_passo_volta(v,N);
        }
    }
    
    cor[u] = 3;
    temp_saida[u] = top_tempo++;
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
    ja_passo_volta(maior,N);
    
    for(i=0;i<N;i++)
    {
        if(cor[i] == 1 && cont[i] != 0)
        {
            ident++;
            ja_passo_volta(i,N);
        }
    }
}

int main()
{
    int N,X,Y; //variaveis da entrada
    int i,j,aux,c = 0,teste = 1;

    while(scanf("%d",&N) && N)
    {
        aux = 0;
        
        for(i=0;i<MAX;i++)
        {
            for(j=0;j<MAX;j++)
                matriz[i][j] = 0;
            cont[i] = 0;
            arvrinha[i] = -1;
        }

        for(i=0;i<N;i++)
        {
            scanf("%d %d",&X,&Y);
            
            matriz[X][Y] = matriz[Y][X] = 1;
            
            cont[X]++;
            if(cont[X] % 2 == 1)
                aux++;
            else
                aux--;
            
            cont[Y]++;
            if(cont[Y] % 2 == 1)
                aux++;
            else
                aux--;
        }

        profundidade(MAX);
        profundidade_volta(MAX);

        printf("Teste %d\n",teste);
        if(ident == 1 && (aux == 0 || aux == 2))
            printf("sim\n");
        else
            printf("nao\n");
        printf("\n");
        teste++;
    }
    
    return 0;
}       



