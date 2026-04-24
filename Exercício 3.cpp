#include <stdio.h>

double energia_par(int s1, int s2, double J)
{
    return -J * s1 * s2;
}

int main()
{
    double J = 1.0;

    int s1, s2;
    double E;

    int pares[4][2] = {
        {1, 1},
        {1, -1},
        {-1, 1},
        {-1, -1}
    };

    int i;

    for (i = 0; i < 4; i++)
    {
        s1 = pares[i][0];
        s2 = pares[i][1];

        E = energia_par(s1, s2, J);

        printf("s1 = %d, s2 = %d -> Energia = %lf\n", s1, s2, E);

        if (s1 == s2)
        {
            printf("Spins paralelos (menor energia)\n");
        }
        else
        {
            printf("Spins antiparalelos (maior energia)\n");
        }
    }

    return 0;
}