/*
 * hilos_tarea.c
 *
 *  Created on: 6 jun. 2018
 *      Author: Fernando Franco
 */
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>


typedef struct {
	 long long int inicio;
	 long long int fin;
}pi;

DWORD WINAPI PI(void *p);
double suma=0;
int main(){
	setvbuf(stderr, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	long long h=50000000000;
	HANDLE count[100];
	pi P[100];
	int x;
	printf("¿Cuantos hilos quieres?[2],[4],[8],[16]\n");
	scanf("%d", &x);
	h=h/x;
	clock_t start=clock();
	for( int i=0;i<x;i++){
		P[i].inicio=(h*i)+1;
		P[i].fin=h*(i+1);
		count[i]=CreateThread(NULL, 0, PI, (void *)&P[i],0,NULL);
	}
	for(int j=0; j<x;j++){
		WaitForSingleObject(count[j], INFINITE);
	}
	clock_t stop= clock();
	long tiempo=abs(1000*(stop-start)/CLOCKS_PER_SEC);
	printf("Tiempo: %li milisegundos\n",tiempo);
	printf("PI: %.10f\n", suma);
	return 0;
}
DWORD WINAPI PI(void *p){
	pi *I=(pi*)p;
	long long i;
	double acum=0;
	for( i=I->inicio;i<=I->fin;i++)
		{
			acum+=((i+1) & 1 ?-1.0 :1.0)/(2*i-1);
		}
	acum=acum*4;
	suma+=acum;
	return 0;
}
