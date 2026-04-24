#include <stdio.h>

int main()
{
    double J = 1 ;
    double T = 1;
    double kB = 1.0;
    double Tc = 2.269;

    double beta = 1.0 / (kB * T);
    double betaJ = beta * J;

    printf("beta = %.4lf\n", beta);
    printf("betaJ = %.4lf\n", betaJ);

    if (T < Tc)
    {
        printf("Sistema abaixo da temperatura critica\n");
    }
    else
    {
        printf("Sistema acima da temperatura critica\n");
    }

    return 0;
}