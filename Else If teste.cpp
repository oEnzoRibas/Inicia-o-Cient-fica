# include <stdio.h>

	int main ()
	{
		double T = 2.5;
		double Tc = 2.269; // temperatura critica do Ising 2D
		if ( T < Tc )
		{
			printf (" Sistema esta na fase FERROMAGNETICA ( ordenada ).\n") ;
		}
		else if ( T == Tc )
		{
			printf (" Sistema esta EXATAMENTE na temperatura critica!\n") ;
		}
		else
		{
			printf (" Sistema esta na fase PARAMAGNETICA ( desordenada).\n") ;
		}
		return 0;
	}