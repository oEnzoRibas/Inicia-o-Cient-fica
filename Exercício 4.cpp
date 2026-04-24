#include <stdio.h>

#define L 10
#define N (L * L)

int nn[N][10];

void boundaries() {
    int i;
    for (i = 0; i < N; i++) {
        nn[i][0] = (i + N - L) % N; // Cima
        nn[i][1] = (i + 1) % N;     // Direita
        nn[i][2] = (i + L) % N;     // Baixo
        nn[i][3] = (i + N - 1) % N; // Esquerda

        // Correcoes de borda
        if (i % L == 0) nn[i][3] = i + L - 1;
        if ((i + 1) % L == 0) nn[i][1] = i - L + 1;
    }
}

int main() {
    boundaries();
    
    printf("Vizinhos do sitio 45:\n");
    printf("Cima: %d | Direita: %d | Baixo: %d | Esquerda: %d\n\n", 
           nn[45][0], nn[45][1], nn[45][2], nn[45][3]);
           
    printf("Vizinhos do sitio 19:\n");
    printf("Cima: %d | Direita: %d | Baixo: %d | Esquerda: %d\n", 
           nn[19][0], nn[19][1], nn[19][2], nn[19][3]);

    return 0;
}