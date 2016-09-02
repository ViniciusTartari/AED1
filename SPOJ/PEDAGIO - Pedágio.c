#include <stdio.h>
#include <stdlib.h>

int tempo;

typedef struct No 
{
    int i; 
    struct No *prox;
}No;

//-------------------------------------------------
typedef struct fila 
{
    No *inicio; 
    No *fim;
}fila;

void inicia(fila *f)
{
    f-> inicio = NULL;
    f-> fim = NULL;
}

void enfila(fila *f, int i)
{
    No *aux;
    aux = (No*)malloc(sizeof(No));
    aux-> i = i;
    aux-> prox = NULL;

    if(f->inicio == NULL && f->fim == NULL)
    {
        f->inicio = aux;
        f->fim = aux;
    } 
    else 
    {
        f->fim->prox = aux;
        f->fim = aux;
    }
}

int desenfila(fila *f)
{
    int x;
    No *aux;
    x = f-> inicio-> i;
    aux = f-> inicio;
    f-> inicio = f-> inicio-> prox;
    free(aux);
    if(f-> inicio == NULL)
        f->fim = NULL;
    return(x);
}
//----------------------------------------------------

void largura(int C, int matriz[][C+2], int L, int lim)
{
    int i,u;
    tempo = 0;
    for(i = 0; i < C; i++)
    {
        matriz[i][C] = 0;
        matriz[i][C+1] = 0;
    }
    fila f;
    inicia(&f);
    enfila(&f, L);
    while(f.inicio != NULL && f.fim != NULL)
    {
        u = desenfila(&f);
        tempo = matriz[u][C] + 1;
        for(i = 0; i < C; i++)
        {
            if((matriz[u][i] == 1 && matriz[i][C+1] == 0))
            {
                enfila(&f, i);
                matriz[i][C+1] = 1;
                matriz[i][C] = tempo;
            }
        }
        matriz[u][C+1] = 2;
    }

}

int main()
{
    int C, E, L, P, a, b, i, j, cont = 1;
    while(scanf("%d %d %d %d", &C, &E, &L, &P) == 4 && 
        (C > 0 && E > 0 && L > 0 && P > 0))
    {
        int matriz[C][C+2];
//matriz de adjacencias
        for(i = 0; i < C; i++)
            for(j = 0; j < C; j++)
                matriz[i][j] = 0;

        for(i = 0; i < E; i++)
        {
            scanf("%d %d", &a, &b);
            matriz[a-1][b-1] = 1;
            matriz[b-1][a-1] = 1;
        }
        printf("Teste %d\n", cont);
        
        largura(C, matriz, L-1, P);

        for(i = 0; i < C; i++)
            if(matriz[i][C] != 0 && matriz[i][C] <= P)
                printf("%d ", i+1);

        printf("\n");
        cont++;
    }
    return 0;
}
