#include <stdio.h>

int tempo;

void verifica(int v, int E, int matriz[][E+1])
{
    matriz[v][E] = 1;
    int i;

    for(i = 0; i < E; i++)
        if(matriz[v][i] == 1 && matriz[i][E] == 0)
            verifica(i, E, matriz);

}

int eh_conexo(int Vo, int E, int matriz[][E+1])
{
    int i, result = 0;

    for(i = 0; i < E; i++)
        matriz[i][E] = 0;
    
    verifica(Vo, E, matriz);
    
    for(i = 0; i  < E; i++)
        if(matriz[i][E] == 0) 
            result = 1;

    return (result);
}

int main()
{
    int E, L, X, Y, i, j, cont = 0;
    while(scanf("%d %d", &E, &L) == 2 && (E!=0 && L!=0))
    {
        int matriz[E][E+1];
        
        //zera a matriz
        for(i = 0; i < E; i++)
            for(j = 0; j < E; j++)
                matriz[i][j] = 0;
        
        //arruma a matriz
        for(i = 0; i < L; i++)
        {
            scanf("%d %d", &X, &Y);
            matriz[X-1][Y-1] = 1;
            matriz[Y-1][X-1] = 1;
        }
        
        cont++;
        printf("Teste %d\n", cont);
        if(eh_conexo(0, E, matriz) == 0)
            printf("normal\n");
        else
            printf("falha\n");
        printf("\n");

    }
    return 0;
}
