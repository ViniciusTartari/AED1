#include <stdio.h>

int tempo;

void visita(int v, int N, int matriz[][N+1])
{
    int i;
    matriz[v][N] = 1;

    for(i = 0; i < N; i++)
        if(matriz[v][i] == 1 && matriz[i][N] == 0)
            visita(i, N, matriz);

}

int verificador(int N, int matriz[][N+1])
{
    int i;
    for(i = 0; i < N; i++)
        if(matriz[i][N] == 0) 
            return (i);
    return (-1);
}

int conexo(int N, int matriz[][N+1])
{
    int i, ret = 0;

    for(i = 0; i < N; i++)
        matriz[i][N] = 0;
    int u = verificador(N, matriz);

    while(u != -1)
    {
        visita(u, N, matriz);
        ret++;
        u = verificador(N, matriz);
    }

    return (ret);
}

int main()
{
    int N, M, a, b, i, j;
    scanf("%d %d", &N, &M);

    int matriz[N][N+1];

    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            matriz[i][j] = 0;

    for(i = 0; i < M; i++)
    {
        scanf("%d %d", &a, &b);
        matriz[a-1][b-1] = 1;
        matriz[b-1][a-1] = 1;
    }
    printf("%d\n", conexo(N, matriz));
    return 0;
}
