/*
 * tarea_2.c
 *
 *  Created on: 6 jun. 2018
 *      Author: Fernando Franco
 */
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

int main()
{
	setvbuf(stderr, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	float pi;
	float acum=0;
	long long int n=50000000000;
	clock_t start=clock();
	for( long long int i=1;i<n;i++)
	{
		acum+=((i+1) & 1 ?-1.0 :1.0)/(2*i-1);
	}
	pi=acum*4;
	clock_t stop= clock();
	long tiempo=1000*(stop-start)/CLOCKS_PER_SEC;
	printf("%li milisegundos\n",tiempo);
	printf("PI= %.10f\n",pi);

	return 0;
}
