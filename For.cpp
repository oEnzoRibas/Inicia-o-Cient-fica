# include <stdio.h>

	# define N 6
	
	int main ()
	{
		int spin [ N ] = {1 , -1 , 1 , 1 , -1 , 1}; // configuracao inicial
		int i ;
		double m = 0.0;
		for ( i = 0; i < N ; i ++)
		{
			m += spin [ i ]; // soma todos os spins
		}
		m = m / N ; // divide pelo numero de sitios
		printf (" Magnetizacao media = %lf\n", m ) ;
			return 0;
		}