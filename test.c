/*
	Elaborar un programa que dado el valor en km/h convierta a metros por segundo.
*/

#include <stdio.h>

int main ()
{
	float kilometros_p_segundo, metros_p_segundo;
	printf("Ingrese cualquier valor: ");
	scanf("%f", &kilometros_p_segundo);
	
	metros_p_segundo = (kilometros_p_segundo * 1000) / 3600;
	
	printf("La velocidad convertida a metros por segundo es igual a: %f", metros_p_segundo);
	
	return 0;
}