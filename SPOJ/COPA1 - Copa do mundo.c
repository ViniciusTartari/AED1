#include <stdio.h>

void rodada(char *times, char *ganhadores, int jogos)
{
  int i, t1,t2;
  for (i=0;i<jogos;i++) 
  {
    scanf("%d %d", &t1, &t2);
    if (t1 > t2)
      ganhadores[i] = times[i*2];
    else
      ganhadores[i] = times[i*2+1];
  }
}  

int main() 
{
  char primera_rodada[16] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P'};
  char segunda_rodada[8], terceira_rodada[4], ultima_rodada[2], winner[2];
  
  rodada(primera_rodada, segunda_rodada,8);
  rodada(segunda_rodada, terceira_rodada,4);
  rodada(terceira_rodada, ultima_rodada,2);
  rodada(ultima_rodada, winner,1);
  
  printf("%c\n", winner[0]);
  return 0;
}
