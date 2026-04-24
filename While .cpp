# include <stdio.h>

	int main ()
	{
		int passo = 0;
		double energia = 100.0; // energia inicial alta ( longe do equilibrio )
		while ( energia > 1.0)
		{
			energia = energia * 0.9; // sistema " relaxa " a cada passo
			passo ++;
		}
		printf (" Sistema equilibrou no passo %d.\n", passo );
		return 0;
	}