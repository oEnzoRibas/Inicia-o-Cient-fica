// Declaracao : tipo_retorno nome ( parametros )

	double calcula_energia ( int s_i , int s_j , double J )
	{
		// Retorna a energia de interacao entre dois spins vizinhos
		return -J * s_i * s_j ;
	}
	#include <stdio.h>
	int main ()
	{
		double E ;
		E = calcula_energia (+1 , +1 , 1.0) ; // spins alinhados : E =-1
	printf(" Energia = %lf\n", E ) ;
	E = calcula_energia (+1 , -1 , 1.0) ; // spins anti - alinhados : E = +1
	printf (" Energia = %lf\n", E ) ;
	
	return 0;
	}