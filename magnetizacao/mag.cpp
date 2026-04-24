#include <bits/stdc++.h> // Comando que inclu� todas as bibliotecas padr�o do C++


#define pmc 1e6
#define L 100
#define N (L*L)

///////////////////////////////////////////////////////////////////////////////////////////////////
using namespace std; // Simplifica a nota��o de alguns comandos da biblioteca padr�o (iostream).
string IntToStr(int n)
{
    stringstream result;
    result << n;
    return result.str();
}
///////////////////////////////////////////////////////////////////////////////////////////////////


int spin[N];
int nn[N][4];


double rand_float()                                 //n�mero aleat�rio entre 0 e 1
{
    return (double)rand() / RAND_MAX;
}

///////////////////////////////////////

void inicializa_rede()                             //come�a com os spins aleat�rios
{
    int i;
    double alpha;

    for (i = 0; i < N; i++)                        // chance 0,5 para 1 e -1
    {
        alpha = rand_float();

        if (alpha < 0.5)
            spin[i] = +1;
        else
            spin[i] = -1;
    }
}

///////////////////////////////////////

void boundaries()                                   //define os vizinhos
{
    int i;

    for (i = 0; i < N; i++)
    {
        nn[i][0] = (i + N - L) % N; // cima
        nn[i][1] = (i + 1) % N; // direita
        nn[i][2] = (i + L) % N; // baixo
        nn[i][3] = (i + N - 1) % N; // esquerda

        if (i % L == 0)                             // corrige as bordas
            nn[i][3] = i + L - 1;

        if ((i + 1) % L == 0)
            nn[i][1] = i - L + 1;
    }
}

////////////////////////////////////

	double calcula_deltaE(int i, double J)            //calcula o delta E
{
    int soma = 0;
    int j;

    for (j = 0; j < 4; j++)                           //soma vizinhos
        soma += spin[nn[i][j]];

    return 2.0 * J * spin[i] * soma;
}

////////////////////////////////////

void metropolis_step(double J, double beta)            //metropolis
{
    int i = rand() % N;

    double deltaE = calcula_deltaE(i, J);

    if (deltaE <= 0)
    {
        spin[i] = -spin[i];
    }
    else
    {
        double r = rand_float();                     //gera probabilidade

        if (r < exp(-beta * deltaE))                 //aceita com probabilidade
            spin[i] = -spin[i];
    }
}

//// FUN�AO DA ENERGIA /////

	double calcula_energia(double J)
{
    int i;
    double H = 0.0;

    for (i = 0; i < N; i++)
    {
        H += -J * spin[i] * spin[nn[i][1]]; // direita
        H += -J * spin[i] * spin[nn[i][2]]; // baixo
    }

    return H;
}

///////////////////////////////

void imprime_rede()                     //imprime a rede
{
    int i;

    for (i = 0; i < N; i++)
    {
        printf("%+d ", spin[i]);

        if ((i + 1) % L == 0)          //forma a matriz
            printf("\n");
    }
}

///////////////////////////

int main()                             //main
{
    double J = 1.0;
    double T = 2.269;
    double beta = 1.0 / T;


    int i,j;
	double mag=0;

	//////////////////////////////////////////////////////////////////////////////////
	string arquivo1;
    arquivo1 = "Magnetizacao_media.txt";
    FILE *f1 = fopen(arquivo1.c_str(),"w+");

    string arquivo2;
    arquivo2 = "Energia.txt";
    FILE *f2 = fopen(arquivo2.c_str(),"w+");
    //////////////////////////////////////////////////////////////////////////////////


    srand(time(NULL));

    boundaries();
    inicializa_rede();

	for (i=0;i<N;i++)
	{
        mag+=spin[i];
	}
    printf("Rede inicial:\n");            //rede 1

	mag=mag/N;                         //fun��o da magnetiza��o

    //imprime_rede();

	printf("\nMagnetizacao Inicial = %lf\n", mag);

    double H_inicial = calcula_energia(J);               //calculo da energia
    printf("\nEnergia inicial = %lf\n", H_inicial);



    for(j=0;j<pmc;j++)                                   //evolu��o do sistema
	{
		for (i=0;i<N; i++)                                   //enquanto o i for menor que N o sistema percorre todos os spins
		{
		    metropolis_step(J, beta);
		}

		mag=0;
		for(i=0;i<N;i++)
        {
            mag+=spin[i];
        }
        mag=mag/N;

		fprintf(f1, "%.4lf \n", mag);

        double H = calcula_energia(J);
        fprintf(f2, "%.4lf \n", H);

	}


    printf("\nRede final:\n");
    //imprime_rede();
    mag=0;

    for(i=0;i<N;i++)
	{
		mag+=spin[i];
        printf("%d", i);
	}
	mag=mag/N;
	printf("\nMagnetizacao Final = %lf\n", mag);
    double H_final = calcula_energia(J);
    printf("\nEnergia final = %lf\n", H_final);
    
    
    fprintf(f1, "%.4lf \n", mag);
    fprintf(f2, "%.4lf \n", H_final);

    return 0;
}