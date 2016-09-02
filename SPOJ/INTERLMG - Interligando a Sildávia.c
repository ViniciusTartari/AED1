#include <stdio.h>
#include <math.h>
#define MAX 1000

double matriz[MAX][MAX], custo[MAX];
int  lista[MAX];

int oopa(int N)
{
        int i, ind = -1;
        double min = MAX*MAX;
        for(i = 0; i < N; i++){
                if(lista[i] == 1 && min > custo[i])
                {
                        ind = i;
                        min = custo[i];
                }
        }
        return ind;
}

void prim(int n)
{
    int i, u, j;
    for(i = 0; i < n; i++)
    {
        custo[i] = MAX*MAX;
        lista[i] = 1;
    }
        
        custo[0] = 0.0000;
    u = oopa(n);
    
    for(i = 0; i < n; i++)
    {
        lista[u] = 0;
        for(j = 0; j < n; j++){
            if(matriz[u][j] > 0 && lista[j] == 1 && matriz[u][j] < custo[j])
                                custo[j] = matriz[u][j];
                }
        u = oopa(n);
    }
}

double calcula(double x1, double x2, double y1, double y2)
{
        double tres, um, dois;
        um   = ( x1-x2) * ( x1-x2);
        dois = ( y1-y2) * ( y1-y2);
        tres = sqrt( um + dois );
        return tres;
}

int main(void)
{
        int N, i;
        while( scanf("%d", &N) && N)
        {

                double coord[2][N],x;
                for(i = 0; i < N; i++)
                    scanf("%lf %lf", &(coord[0][i]), &(coord[1][i]));
    
                if(N == 1)
                    printf("0.0000\n");
                else if(N == 2)
                {
                        x = calcula( coord[0][0], coord[0][1], coord[1][0], coord[1][1]);
                        printf("%.4lf\n", x);
                }
                else
                {
                        int j, maior = 1;
                        double dist;
                        
                        x = -1;
                        
                        for(i = 0; i < N; i++)
                        {
                                for(j = 0; j < N; j++)
                                        if(j == i)
                                                matriz[i][j] = 0;
                                        else
                                        {
                                                dist = calcula( coord[0][i], coord[0][j], coord[1][i], coord[1][j] );
                                                matriz[i][j] = dist; matriz[j][i] = dist;
                                        }
                        }
                        prim(N);
                        for(i = 1; i < N; i++)
                            if(custo[maior] < custo[i])
                                maior = i;
                                        
                        printf("%.4lf\n", custo[maior]);
                }       
        }       
        return 0;
}


