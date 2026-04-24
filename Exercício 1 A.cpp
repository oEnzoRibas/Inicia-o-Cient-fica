#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define L 10
#define N (L*L)

int spin[N];
//usar double para maior precisão
	double rand_float()
{
	return (double)rand() / RAND_MAX;
}

//inicia a rede
void inicializa_rede()
{
    int i;
    double alpha;

    for (i = 0; i < N; i++)
    {
        alpha = rand_float();

        if (alpha < 0.5)
        {
            spin[i] = +1;
        }
        else
        {
            spin[i] = -1;
        }
    }
}

int main()
{
    int i;

// acompanhar o relógio para número aleatório
    srand(time(NULL));

    inicializa_rede();

    for (i = 0; i < N; i++)
    {
        printf("%2d ", spin[i]);

        //formar matriz
        if ((i + 1) % L == 0)
            printf("\n");
    }

    return 0;
}