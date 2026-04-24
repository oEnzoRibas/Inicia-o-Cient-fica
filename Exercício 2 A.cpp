#include <stdio.h>

#define L 4
#define N (L*L)

int spin[N];
int nn[N][4];

	void boundaries()
{
    int i;

    for (i = 0; i < N; i++)
    {
        nn[i][0] = (i + N - L) % N; // cima
        nn[i][1] = (i + 1) % N;     // direita
        nn[i][2] = (i + L) % N;     // baixo
        nn[i][3] = (i + N - 1) % N; // esquerda

        if (i % L == 0)
            nn[i][3] = i + L - 1;

        if ((i + 1) % L == 0)
            nn[i][1] = i - L + 1;
    }
}

// delta e
double calcula_deltaE(int i, double J)
{
    int soma_vizinhos = 0;
    int j;

// soma dos vizinhos
    for (j = 0; j < 4; j++)
    {
        soma_vizinhos += spin[nn[i][j]];
    }

//variação de energia
    return 2.0 * J * spin[i] * soma_vizinhos;
}

int main()
{
    int i;

//spin tudo +1
    for (i = 0; i < N; i++)
        spin[i] = +1;

    boundaries();

    int site = 5;
    double J = 1.0;

    double deltaE = calcula_deltaE(site, J);

    printf("Delta E no sitio %d = %lf\n", site, deltaE);

    return 0;
}