#include <stdio.h>

int resolve(int N, int matriz[N][N+4])
{
    int i, valor;
    for(i = 0; i < N; i++)
    {
        matriz[i][N] = -1;
        matriz[i][N+1] = -1;
        matriz[i][N+2] = 1;
    }

    matriz[0][N] = 0;
    valor = limpadora(N, matriz);
    while(valor >= 0)
    {
        matriz[valor][N+2] = 0;
        for(i = 0; i < N; i++)
        {
            if(matriz[i][N] == -1 && matriz[i][valor] > 0 && matriz[i][N+2] == 1)
            {
                matriz[i][N] = matriz[valor][i];
                matriz[i][N+1] = valor;
            }
            else if( matriz[valor][i] > 0 && matriz[i][N+2] == 1 && matriz[valor][i] < matriz[i][N])
            {
                matriz[i][N] = matriz[valor][i];
                matriz[i][N+1] = valor;
            }
        }
        valor = limpadora(N, matriz);
    }
}

int limpadora(int N, int matriz[][N+4])
{
    int i, X = -1, valor = 999999999;//para testar; arrumar antes de mandar pro spoj;
    for(i = 0; i < N; i++)
    {
        if(matriz[i][N+2] == 1 && matriz[i][N] != -1 && valor > matriz[i][N])
        {
            valor = matriz[i][N];
            X = i;
        }
    }
    return (X);
}

int main()
{
        int P, Q, U, N, M, i, j, Vo, cont=0;
        scanf("%d %d", &N, &M);
        int matriz[N][N + 4];

        for(i = 0; i < N; i++)
            for(j = 0; j < N; j++)
                matriz[i][j] = 0;

        for(i = 0; i < M; i++)
        {
            scanf("%d %d %d", &P, &Q, &U);
            matriz[P][Q] = U;
            matriz[Q][P] = U;
//monta matriz com os pesos
        }

        resolve(N, matriz);

        for(i = 0; i < N; i++)
        if(matriz[i][N] != -1)
            cont += matriz[i][N];

        printf("%d\n", cont);

        return 0;
}

