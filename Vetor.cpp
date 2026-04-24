# include <stdio.h>

	# define N 5 // Define a constante N como 5 (sem ponto e virgula no define !
	int main ()
	{
		int spin [ N ]; // Vetor de N inteiros
		int i ;
		// Inicializa todos os spins como +1
		spin [0] = +1;
		spin [1] = -1;
		spin [2] = +1;
		spin [3] = -1;
		spin [4] = +1;
		// Acessa e imprime o segundo elemento ( indice comeca em 0!)
		printf (" spin [0] = %d\n", spin [0]) ;
return 0;
	}