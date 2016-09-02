#include <stdio.h>
#define MAX 10
#define MAX_VALUE 100

int g[MAX][MAX], v[MAX][MAX], result;

void FunctionNonSense(int N, int M, int Xo, int Yo, int value)
{
    if(g[Yo][Xo] == 0 && result > value)
    {
        result = value;
        return;
    }

    v[Yo][Xo] = value++;
    if(Yo - 1 >= 0 && g[Yo-1][Xo] < 2 && v[Yo-1][Xo] > value)
        FunctionNonSense(N, M, Xo, Yo-1, value);
    if(Xo - 1 >= 0 && g[Yo][Xo-1] < 2 && v[Yo][Xo-1] > value)
        FunctionNonSense(N, M, Xo-1, Yo, value);
    if(Yo+1 < N && g[Yo+1][Xo] < 2 && v[Yo+1][Xo] > value)
        FunctionNonSense(N, M, Xo, Yo+1, value);
    if(Xo+1 < M && g[Yo][Xo+1] < 2 && v[Yo][Xo+1] > value)
        FunctionNonSense(N, M, Xo+1, Yo, value);
}

int main(void)
{
    int N, M, i, j, Yo, Xo;
    scanf("%d %d", &N, &M);
    for(i = 0; i < N; i++)
        for(j =  0; j < M; j++)
        {
            scanf("%d", &( g[i][j] ) );
            v[i][j] = MAX_VALUE;
            if(g[i][j] == 3)
            {
                Yo = i;
                Xo = j;
            }
        }

    result = MAX_VALUE;
    FunctionNonSense(N, M, Xo, Yo, 0);
    printf("%d\n", result);
    return 0;
}

