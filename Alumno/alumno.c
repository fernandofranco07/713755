#include <stdio.h>
#include <stdlib.h>
#define enter printf("\n");
#define MAX_AL 1

typedef struct {
	int edad;
	char nombre[100];
	int numero_cuenta;
	char carrera[100];
}alumno;

alumno LEER_AL();
void Mostrar_Al(alumno estudiante);

int main(){
	setvbuf(stderr, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	static alumno alumnos[MAX_AL];
	int x,i;
	alumno *apuntador;
	apuntador=&alumnos[MAX_AL];
	printf("El máximo es de alumnos es 20"); enter;

do{
	printf("***MENÚ***");enter;
	printf("¿Desea guardar alumnos?(presione 1)\n¿Desea ver a un alumno?(presione 2)\n¿Desea eliminar alumnos?(presione 3)\n¿Desea Buscar un alumno?(presione 4)");enter;
	scanf("%d", &x);enter;
	if(x==1){
		for( i=0;i<MAX_AL;i++){
			printf("-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-");enter;
			printf("Alumno %d",i+1);
			LEER_AL(apuntador[i]);
			printf("-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-");enter;
		}
	}
	if(x==2){
		for(i=0;i<MAX_AL; i++){
			printf("-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-");enter;
			printf("Alumno %d",i+1);
			Mostrar_Al(apuntador[i]);
		}
	}
	if (x==3){
		printf("Error al procesar la solicitud");
	}
	if(x==4){
		printf("Error al procesar la solicitud");
	}
}while(x<5);
	system("Pause");
	return 0;
}
alumno LEER_AL(){
	alumno estudiante;
	enter;
	printf("Escribe el nombre: ");;
	fflush(stdin);
	gets(estudiante.nombre);
	printf("Proporciona la edad: ");
	scanf("%d", &estudiante.edad);
	printf("Proporciona el número de cuenta: ");
	scanf("%d",&estudiante.numero_cuenta );
	printf("Proporciona la carrera: ");
	fflush(stdin);
	gets(estudiante.carrera);

	return estudiante;
}
void Mostrar_Al(alumno estudiante){
	enter;
	printf("Nombre del alumno: %s", estudiante.nombre);enter;
	printf("Edad: %d",estudiante.edad);enter;
	printf("No. Cuuenta: %d", estudiante.numero_cuenta);enter;
	printf("Carrera: %s", estudiante.carrera);enter;

}
