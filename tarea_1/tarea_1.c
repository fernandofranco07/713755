/*
 * tarea_1.c
 *
 *  Created on: 24 may. 2018
 *      Author: Fernando Franco
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	char nombre[15];
	float calificacion;
} Profesor;
float averageArray(Profesor per3[]  , int persona3);
void readArray(Profesor per[], int persona);
void sortArray(Profesor per3[], int persona3);
void mergeArrays(Profesor per[] , int persona, Profesor per2[], int persona2, Profesor per3[], int persona3);
void printArray(Profesor per3[], int persona3);


int main(){
	setvbuf(stderr, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	printf("Las listas son de máximo 20 elementos c/u\n");
	Profesor per[20];
	Profesor per2[20];
	Profesor per3[40];
	int n, n1;
	printf("¿Cuántos maestros tienes?(lista 1)");
	scanf("%d",&n);
	fflush(stdin);
	readArray(per, n);
	printf("¿Cuántos maestros tienes?(lista 2)");
	scanf("%d",&n1);
	fflush(stdin);
	readArray(per2,n1);
	int i=n+n1;
	mergeArrays(per, n, per2,n1, per3, i);
	averageArray(per3, i);
	sortArray(per3, i);
	printArray(per3, i);

	return 0;
}
float averageArray(Profesor per3[]  , int persona3){
	int i, j;
	int av;
	Profesor *pointer=per3;
	int acum1, repetidos;
	for(i=0; i<persona3;i++){
		acum1=0;
		repetidos=1;
		for(j=0;j<persona3;j++){
			if(strcmp((*(pointer)).nombre,(*(pointer+j)).nombre)==0){
				acum1=(*(pointer)).calificacion+(*(pointer+j)).calificacion;
				repetidos++;
			}
		}
		av=acum1/repetidos;
	}
	return av;
}

void readArray(Profesor per[], int persona){
	Profesor *p=per;
	for (int i=0; i<persona; i++){
		//scanf("%[^\n] %f",*(p+i+1).nombre, &(*(p+i+1)).calificacion );
		scanf("%s[^\n] ", (*(p+i)).nombre);
		scanf(" %f", &(*(p+i)).calificacion);
	}
}
//void readArray(Profesor per[20], int persona){//prototipo de otra funcion(otra opción)
//	for( int i =0; i<persona;i++){
//		printf("¿Cuál es el nombre del profesor?¿Cuál es su calificación?\n");
//		gets(per[i].nombre);
//		fflush(stdin);
//		scanf(" %f", &per[i].calificacion);
//	}
//}

//void sortArray(Profesor per[20] , int i){//prototipo de otra funcion(otra opción)
//	Profesor sort;
//		for(int x=0; x<i;x++){
//			if(per[x].calificacion>per[x+1].calificacion){
//				sort=per[x];
//				per[x]=per[x+1];
//				per[x+1]=sort;
//			}
//		}
//}
void sortArray(Profesor per3[40], int persona3){
	Profesor *sort=per3;
	float x;
	int i;
	for (i=0; i<persona3;i++){
		if(sort->calificacion>(sort+i+1)->calificacion){
			x=sort->calificacion;
			sort->calificacion=(sort+i+1)->calificacion;
			(sort+i+1)->calificacion=x;
		}
	}
}

void mergeArrays(Profesor per[] , int persona, Profesor per2[], int persona2, Profesor per3[], int persona3){
	Profesor *arr=per;
	Profesor *arr2=per2;
	Profesor *arrF=per3;
	int i, h;
	//persona3=0;
	for(i=0; i<persona;i++){
		strcpy((arrF+i)->nombre, (arr+i)->nombre);
		(arrF+i)->calificacion=(arr+i)->calificacion;
	}
	for(h=0;h<persona2;h++){
		strcpy((arrF+h)->nombre, (arr2+i)->nombre);
		(arrF+h)->calificacion=(arr2+i)->calificacion;
	}
//	for (i=0;i<persona;i++){//prototipo de otra funcion(otra opción)
//		strcpy((arrF+persona3)->nombre, (arr+i)->nombre);
//		(arrF+persona3)->calificacion=(arr+i)->calificacion;
//		persona3++;
//	}
//	for(h=0;h<persona2;h++){//prototipo de otra funcion(otra opción)
//		strcpy((arrF+persona3)->nombre, (arr2+i)->nombre);
//				(arrF+persona3)->calificacion=(arr2+i)->calificacion;
//				persona3++;
//	}
}


//void printArray(Profesor per3[], int persona){ //prototipo de otra funcion(otra opción)
//	int i;
//	for(i=0; i<persona;i++){
//		printf("Nombre: %s Calificación: %f\n", per3[i].nombre, per3[i].calificacion);
//
//	}
//}

void printArray(Profesor per3[], int persona3){
	Profesor *p=per3;
	for(int i=0; i<persona3;i++){
		printf("Nombre: %s  \t",&(*(p+i)).nombre);
		printf("Calificación: %f\n",&(*(p+i)).calificacion );
	}
}
