#include <stdio.h>

void ordena(int t, int v[2][t])
{
    int i, j, aux;
    for(i = 0; i < t; i++)
    {
        for(j = i; j < t-1; j++)
        {
            if(v[0][j] > v[0][j+1] || (v[0][j] == v[0][j+1] && v[1][j] > v[1][j+1]))
            {
                aux = v[0][j];
                v[0][j] = v[0][j+1];
                v[0][j+1] = aux;

                aux = v[1][j];
                v[1][j] = v[1][j+1];
                v[1][j+1] = aux;

            }
        }
    }
}

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
    int i, X = -1, valor = 999999999;//ta funfando mas n eh bom usa valor fixo
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
    int N, M, X, Y, Z, i, j, Vo, teste = 1;
    while(scanf("%d %d", &N, &M) == 2 && N != 0 && M != 0)
    {
        int matriz[N][N+4];

        for(i = 0; i < N; i++)
            for(j = 0; j < N; j++)
                matriz[i][j] = 0;

        for(i = 0; i < M; i++)
        {
            scanf("%d %d %d", &X, &Y, &Z);
            matriz[X-1][Y-1] = Z;
            matriz[Y-1][X-1] = Z;
        }

        resolve(N, matriz);

        int v[2][N-1], cont = 0;

        for(i = 1; i < N; i++)
        {
            if(i > matriz[i][N+1])
            {
                v[0][cont] = matriz[i][N+1];
                v[1][cont] = i;
            }
            else
            {
                v[1][cont] = matriz[i][N+1];
                v[0][cont] = i;
            }
            cont++;
        }

        ordena(N-1, v);

        printf("Teste %d\n", teste++);
        for(i = 0; i < N-1; i++)
            printf("%d %d\n", v[0][i]+1, v[1][i]+1);

        printf("\n");
    }
    return 0;
}
