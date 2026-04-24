#include <math.h>
#include <stdio.h>

	float rand_float()
	{
	return(float)rand() / (float)RAND_MAX;
	}
	
		int rand_sitio()
		{
		return rand() %N;	
		}