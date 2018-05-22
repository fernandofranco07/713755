/*
 * cifrado.c
 *
 *  Created on: 22/05/2018
 *      Author: ie713755
 */
#include<stdio.h>
#include<stdlib.h>

int main(){
	setvbuf(stderr, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	char cadena[];
	int desplazamiento;
	printf ("Proporciona tu cadena \n");
	scanf("%s", cadena);

	printf("Desaplazamiento: ");
	scanf("%d", &desplazamiento);
	for(int i=0; i<strlen(cadena);i++)
	{
		//
	}
	system("Pause");
	return 0;
}
