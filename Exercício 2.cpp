#include <stdio.h>

#define N 10

int main() {
    // 1. Declaracao do vetor
    int spin[N];
    int i;
    double M = 0.0;
    double m = 0.0;
    double H = 0.0;
    double J = 1.0;

    // 2. Inicializacao alternada usando laco for
    for (i = 0; i < N; i++) {
        if (i % 2 == 0) {
            spin[i] = +1;
        } else {
            spin[i] = -1;
        }
    }

    // 3. Calculo da magnetizacao
    for (i = 0; i < N; i++) {
        M += spin[i];
    }
    m = M / N;
    
    printf("Magnetizacao total M = %.2lf\n", M);
    printf("Magnetizacao por sitio m = %.2lf\n", m);

    // 4. Calculo da energia da cadeia 1D
    for (i = 0; i < N - 1; i++) {
        H += -J * spin[i] * spin[i+1];
    }
    
    printf("Energia da cadeia H = %.2lf\n", H);

    return 0;
}