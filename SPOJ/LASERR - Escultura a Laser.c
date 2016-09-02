#include <stdio.h>

int main()
{
	int i, h, c, qnt=0, inicio, ant, atual;
	while (scanf("%d %d", &h, &c) && (h || c))
	{
		inicio = h;
		ant = h;
		int sobe = 0;
		for (i = 0; i < c; i++)
		{
			scanf("%d", &atual);
			if (atual < ant)
				sobe = 0;
			else if (atual > ant)
			{
				if (!sobe)
					qnt += inicio - ant;
				inicio = atual;
				sobe = 1;
			}
			ant = atual;
		}
		if (!sobe)
			qnt += inicio - ant;
		printf("%d\n", qnt);
		qnt=0;
	}
	return 0;
}
