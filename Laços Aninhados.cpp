# include <stdio.h>

	# define L 4 // lado da rede : L x L sitios
	int main ()
	{
		int x , y ;
		int spin [ L ][ L ]; // Inicializa todos os spins como +1
		for ( x = 0; x < L ; x ++)
		{
			for ( y = 0; y < L ; y ++)
			{
				spin [ x ][ y ] = +1;
			}
		}
		// Imprime a rede como uma grade
		for ( x = 0; x < L ; x ++)
		{
			for ( y = 0; y < L ; y ++)
			{
				printf ("%+d ", spin [ x ][ y ]) ;
			}
			printf ("\n") ;}
			return 0;
	}
	