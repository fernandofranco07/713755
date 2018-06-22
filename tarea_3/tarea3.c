/*
 * tarea3.c
 *
 *  Created on: 13 jun. 2018
 *      Author: Fernando Franco
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

typedef struct {
	int dia;
	int mes;
	int anio;
}fecha;

typedef struct {
	int id;
	char nombre[50];
	char paterno[50];
	char materno[50];
	fecha ff;
}clientes;
typedef struct{
	int id_cuenta;
	int saldo;
	clientes cli;
	fecha fecha_ape;
}cuenta;
typedef struct{
	int id_trans;
	int cuenta_or;
	int cuenta_des;
	int cantidad;
	char tipo_mov[20];
	fecha ff;
}transac;

char dir_cli[100], dir_cuen[100],dir_trans[100], dir_aux[100];
char full_rut[100], full_rut2[100];

void crearCliente(FILE *client);
void imprimirCliente(FILE *f);
void Buscar_cliente(FILE *f);
void eliminarCliente(FILE *f);

void crearCuenta(FILE *ff,FILE *f);
void imprimirCuenta(FILE *ff, FILE *f);
void buscarCuenta(FILE *ff, FILE *f);
void eliminarCuenta(FILE *ff);

void deposito(FILE *d, FILE *ff);
void retiro(FILE *d,FILE *ff);
void imprimirTransfe(FILE *d, FILE *ff);

int main(){
	setvbuf(stderr, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	int x, y;

	FILE *clientes;
	FILE *cuentas;
	FILE *transacciones;
	FILE *MYDB;
	MYDB=fopen("mydb.sys", "r");
	if(MYDB==NULL){
		printf("¿En donde quieres guardar tus archivos? (ejemplo: C:\\Users\\docs\\...)\n");
		scanf("%[^\n]", full_rut);
		strcpy(dir_cli, full_rut);
		strcat(dir_cli,"\\clientes.dat");
		strcpy(dir_cuen,full_rut);
		strcat(dir_cuen,"\\cuentas.dat");
		strcpy(dir_trans,full_rut);
		strcat(dir_trans,"\\transferencias.dat");
		strcpy(dir_aux, full_rut);
		strcat(dir_aux,"\\auxiliar_cli.dat");

		MYDB=fopen("mydb.sys", "w+");
		fprintf(MYDB, "%s",full_rut);
		fclose(MYDB);

		clientes=fopen(dir_cli, "a+b");
		if(clientes==NULL)
			printf("Error en el archivo\n");
		cuentas=fopen(dir_cuen,"a+b");
		if(cuentas==NULL)
			printf("Error en el archivo\n");
		transacciones=fopen(dir_trans,"a+b");
		if(transacciones==NULL)
			printf("Error en el archivo\n");

		int prim=0;
		fwrite(&prim, sizeof(int), 1, clientes);
		fwrite(&prim, sizeof(int), 1, cuentas);
		fwrite(&prim, sizeof(int), 1, transacciones);
		fclose(clientes);
		fclose(cuentas);
		fclose(transacciones);
	}
	else{

		fscanf(MYDB, "%[^\n]",full_rut2);
		strcpy(dir_cli, full_rut2);
		strcat(dir_cli,"\\clientes.dat");
		strcpy(dir_cuen,full_rut2);
		strcat(dir_cuen,"\\cuentas.dat");
		strcpy(dir_trans,full_rut2);
		strcat(dir_trans,"\\transferencias.dat");
		fclose(MYDB);
	}

	printf("<<Sistema MyDB>>\n");
	do{
		printf("1. Clientes\n2. Cuentas\n3. Transacciones\n4. Salir\n");
		scanf("%d",&x);
		while(x<1||x>4){
			printf("Opción no valida\nIngresa nuevamente a la opción que gustes\n");
			scanf("%d", &x);
		}
		fflush(stdin);
		switch(x){
    	case 1:
    		printf("1. Nuevo Cliente\n2. Buscar Cliente\n3. Eliminar Cliente\n4. Imprimir Clientes\n");
    		scanf("%d", &y);
    		while(x<1||x>4){
    					printf("Opción no valida\nIngresa nuevamente a la opción que gustes\n");
    					scanf("%d", &x);
    				}
    		switch(y){
    			case 1:
    				clientes=fopen(dir_cli, "a+b");
    				crearCliente(clientes);
    				fclose(clientes);
    				break;
    			case 2:
    				clientes=fopen(dir_cli,"a+b");
    				 Buscar_cliente(clientes);
    				 fclose(clientes);
    				break;
    			case 3:
    				clientes=fopen(dir_cli, "a+b");
    				eliminarCliente(clientes);
    				fclose(clientes);
    				break;
    			case 4:
    				clientes=fopen(dir_cli, "a+b");
    				imprimirCliente(clientes);
    				fclose(clientes);
					break;
    			}
    		break;

    	case 2:
    		printf("1. Nueva Cuenta\n2. Buscar Cuenta\n3. Eliminar Cuenta\n4. Imprimir Cuentas\n");
    		scanf("%d", &y);
    		while(x<1||x>4){
				printf("Opción no valida\nIngresa nuevamente a la opción que gustes\n");
				scanf("%d", &x);
				}
    		switch(y){
    		case 1:
    			cuentas=fopen(dir_cuen, "a+b");
    			crearCuenta(cuentas, clientes);
    			fclose(cuentas);
    			break;
    		case 2:
    			cuentas=fopen(dir_cuen,"a+b");
    			buscarCuenta(cuentas,clientes);
    			fclose(cuentas);
    			break;

    		case 3:
    			cuentas=fopen(dir_cuen,"a+b");
    			eliminarCuenta(cuentas);
    			fclose(cuentas);
    			break;
    		case 4:
    			cuentas=fopen(dir_cuen, "a+b");
    			imprimirCuenta(cuentas, clientes);
    			fclose(cuentas);
    			break;
    		}
    		break;

    	case 3:
    		printf("1. Depósito\n2. Retiro\n3. Transferencia\n");
    		scanf("%d", &y);
    		while(x<1||x>3){
    					printf("Opción no valida\nIngresa nuevamente a la opción que gustes\n");
    					scanf("%d", &x);
    				}
    		switch(y){
    		case 1:
    			transacciones=fopen(dir_trans,"a+b");
    			deposito(transacciones, cuentas);
    			fclose(transacciones);
    			break;
    		case 2:
    			transacciones=fopen(dir_trans,"a+b");
    			retiro(transacciones, cuentas);
    			fclose(transacciones);
    			break;
    		case 3:
    			transacciones=fopen(dir_trans,"a+b");
    			imprimirTransfe(transacciones, cuentas);
    			fclose(transacciones);

    			break;
    		}
    		break;

    	case 4:
    		return 0;
			}
	}while(x>1||x<4);
  return 0;
}
void crearCliente(FILE *client){
	clientes cli;
	int quant;

	client=fopen(dir_cli, "rb");
	fread(&quant, sizeof(int), 1, client);
	fclose(client);
	abs(quant++);

	client=fopen(dir_cli,"a+b");
	cli.id=quant;
	fflush(stdin);
	printf("Nombre(s): ");
	scanf("%[^\n]",cli.nombre );
	printf("Apellido Paterno: ");
	scanf("%s",cli.paterno);
	printf("Apellido Materno: ");
	scanf("%s", cli.materno);
	fflush(stdin);
	printf("Ingresa tu fecha de nacimiento(dd/mm/aaa)\n");
	scanf("%d ", &cli.ff.dia);
	scanf("%d ", &cli.ff.mes);
	scanf("%d", &cli.ff.anio);

	fwrite(&cli, sizeof(clientes), 1, client);
	fclose(client);

	client=fopen(dir_cli, "r+b");
	fwrite(&quant, sizeof(int), 1, client);
	fclose(client);
}
void imprimirCliente(FILE *f){
		int x;
		f=fopen(dir_cli,"rb");
		fread(&x, sizeof(int), 1, f);
		clientes cli;
		printf("%-20s %-20s %-20s %-20s %-20s\n","ID", "Nombre", "Apellido Parterno", "Apellido Materno", "Fecha de nacimiento");
		while(fread(&cli,sizeof(clientes), 1,f)==1){
			printf("%-20d %-20s %-20s %-20s  %02d/%02d/%d\n", cli.id,cli.nombre,cli.paterno,cli.materno,cli.ff.dia,cli.ff.mes,cli.ff.anio);
		}
		fclose(f);
}
void Buscar_cliente(FILE *f){
	int x, id;
	f=fopen(dir_cli,"rb");
	fread(&x, sizeof(int), 1, f);
	clientes cli;
	printf("Ingresa el ID del usuario que quieres\n");
	scanf("%d",&id);
	while(fread(&cli,sizeof(clientes), 1,f)==1){
		if(cli.id==id){
			printf("%-20s %-20s %-20s %-20s %-20s\n","ID", "Nombre", "Apellido Parterno", "Apellido Materno", "Fecha de nacimiento");
		    printf("%-20d %-20s %-20s %-20s  %02d/%02d/%d\n", cli.id,cli.nombre,cli.paterno,cli.materno,cli.ff.dia,cli.ff.mes,cli.ff.anio);
		    fclose(f);
		}
	}
}
void eliminarCliente(FILE *f){
	int a, cont=0, true=0,ID;
	printf("Ingresa el ID del usuario al que quieras borrar\n");
	scanf("%d",&ID);
	f=fopen(dir_cli, "r+b");
	fread(&a, sizeof(int),1,f);
	clientes cli;
	clientes *array=(clientes *)malloc(sizeof(clientes));
	while(fread(&cli,sizeof(clientes),1,f)==1)
	{
		if(ID!=cli.id)
		{
			(array+cont)->id=cli.id;
			strcpy((array+cont)->nombre,cli.nombre);
			strcpy((array+cont)->paterno,cli.paterno);
			strcpy((array+cont)->materno,cli.materno);
			(array+cont)->ff=cli.ff;
			cont++;
			array=(clientes*)realloc(array, sizeof(clientes)*(cont+1));
			true=1;

		}
	}
	if(true==1)
		printf("Este ID no está en el archivo.\n");
	fclose(f);
	f=fopen(dir_cli, "wb");
	fwrite(&a, sizeof(int),1,f);
	fclose(f);
	f=fopen(dir_cli,"a+b");
	fwrite(array,sizeof(clientes),cont--,f);
	fclose(f);
	free(array);
	printf("Eliminado exitosamente\n");
}
void crearCuenta(FILE *ff, FILE *f){
		cuenta cuen;
		int id,id_cli;
		int ID;

		f=fopen(dir_cli,"rb");
		printf("Ingresa el ID al que quieres enlazar la cuenta\n");
		scanf("%d", &id);

		ff=fopen(dir_cuen, "rb");
		fread(&ID, sizeof(int), 1, ff);
		fclose(ff);
		ID++;
		if(fread(&id_cli,sizeof(int),1,f)==0){
			printf("Usuario no encontrado\nIntente de nuevo\n");
			scanf("%d",&id);
		}
		ff=fopen(dir_cuen,"a+b");
		cuen.cli.id=id;
		cuen.id_cuenta=ID;
		fflush(stdin);
		printf("Ingresa el saldo inicial: \n");
		scanf("%d",&cuen.saldo);
		printf("Fecha de apertura de la cuenta(dd/mm/aaa)\n");
		scanf("%d ", &cuen.fecha_ape.dia);
		scanf("%d ", &cuen.fecha_ape.mes);
		scanf("%d", &cuen.fecha_ape.anio);

		fwrite(&cuen, sizeof(cuenta), 1, ff);
		fclose(f);
		fclose(ff);

		ff=fopen(dir_cuen, "r+b");
		fwrite(&ID, sizeof(int), 1, ff);
		fclose(ff);
}
void imprimirCuenta(FILE *ff, FILE *f){
	int x;
	int id_cli;
	ff=fopen(dir_cuen,"rb");
	f=fopen(dir_cli,"rb");
	fread(&x, sizeof(int), 1, ff);
	fread(&id_cli,sizeof(int),1, f);
	cuenta cuen;
	clientes cli;
	printf("%-20s %-20s %-20s %-20s %-20s\n","ID.Cuenta", "ID.Usuario", "Nombre del usuario", "Saldo", "Fecha de apertura");
	while(fread(&cuen,sizeof(cuenta), 1,ff)==1){
		fread(&cli,sizeof(clientes),1,f);
		printf("%-20d %-20d %-20s $%-20d   %02d/%02d/%d\n",cuen.id_cuenta, cli.id,cli.nombre,cuen.saldo, cuen.fecha_ape.dia,cuen.fecha_ape.mes,cuen.fecha_ape.anio);
	}
	fclose(f);
	fclose(ff);
}
void buscarCuenta(FILE *ff,FILE *f){
	int x, id,id_cli;
	ff=fopen(dir_cuen,"rb");
	f=fopen(dir_cli,"rb");
	fread(&x, sizeof(int), 1, ff);
	fread(&id_cli,sizeof(int),1,f);
	cuenta cuen;
	clientes cli;
	printf("Ingresa el ID del usuario que quieres la cuenta\n");
	scanf("%d",&id);
	if(fread(&cuen,sizeof(cuenta), 1,ff)==0)
		printf("Cuenta no encontrada\n");
	while(fread(&cuen,sizeof(cuenta), 1,ff)==1){
			fread(&cli,sizeof(clientes),1,f);
			printf("%-20s %-20s %-20s %-20s %-20s\n","ID.Cuenta", "ID.Usuario", "Nombre del usuario", "Saldo", "Fecha de apertura");
			printf("%-20d %-20d %-20s $%-20d   %02d/%02d/%d\n",cuen.id_cuenta, cli.id,cli.nombre,cuen.saldo, cuen.fecha_ape.dia,cuen.fecha_ape.mes,cuen.fecha_ape.anio);
		}
	fclose(f);
	fclose(ff);
}
void eliminarCuenta(FILE *ff){
	int a, cont=0,ID;
	printf("Ingresa el ID del usuario al que quieras borrar la cuenta\n");
	scanf("%d",&ID);
	while(fread(&ID,sizeof(int),1, ff)==0){
			printf("Error en el ID de la cuenta a depositar\nIntente de nuevo\n");
			scanf("%d",&ID);
		}
	ff=fopen(dir_cuen, "r+b");
	fread(&a, sizeof(int),1,ff);
	cuenta cuen;
	cuenta *array=(cuenta *)malloc(sizeof(cuenta));

	while(fread(&cuen,sizeof(clientes),1,ff)==1)
	{
		if(ID!=cuen.id_cuenta)
		{
			(array+cont)->id_cuenta=cuen.id_cuenta;
			(array+cont)->saldo=cuen.saldo;
			(array+cont)->fecha_ape=cuen.fecha_ape;
			cont++;
			array=(cuenta*)realloc(array, sizeof(cuenta)*(cont+1));
		}
	}

	fclose(ff);
	ff=fopen(dir_cuen, "wb");
	fwrite(&a, sizeof(int),1,ff);
	fclose(ff);
	ff=fopen(dir_cuen,"a+b");
	fwrite(array,sizeof(clientes),cont--,ff);
	fclose(ff);
	free(array);
}
void deposito(FILE *d, FILE *ff){
	int cantidad,id_cuentas, id_transacciones;
	transac deposito;
	cuenta mome;
	strcpy(deposito.tipo_mov,"Deposito");

	d=fopen(dir_trans,"rb");
	fread(&id_transacciones, sizeof(int), 1, ff);
	fclose(d);
	id_transacciones++;
	ff=fopen(dir_cuen, "rb");
		if(d==NULL)
			printf("Error en el archivo\n");
	printf("Ingresa el ID de la cuenta a la que vas a depositar\n");
	scanf("%d", &id_cuentas);
	while(!(fread(&id_cuentas,sizeof(int),1, ff))){
		printf("Error en el ID de la cuenta a depositar\nIntente de nuevo\n");
		scanf("%d",&id_cuentas);
	}

	fread(&id_cuentas,sizeof(int),1,ff);
	printf("Ingrese la fecha de la operación(dd/mm/aaaa)\n");
	scanf("%d %d %d", &deposito.ff.dia,&deposito.ff.mes,&deposito.ff.anio);
	printf("Ingresa la cantidad a depositar\n");
	scanf("%d",&cantidad);
	deposito.cantidad=cantidad;
	deposito.id_trans=id_transacciones;

	ff=fopen(dir_cuen,"r+b");
	fseek(ff,sizeof(int),SEEK_CUR);
	while(fread(&mome,sizeof(cuenta),1,ff)==1){
		if(mome.id_cuenta==id_cuentas){
			mome.saldo= mome.saldo+cantidad;
			fseek(ff,-sizeof(cuenta),SEEK_CUR);
			fwrite(&mome.saldo,sizeof(cuenta),1,ff);
		}
	}
	fclose(ff);
	fclose(ff);
	fclose(d);
}
void retiro(FILE *d,FILE *ff){
	int id,cantidad;
	printf("Ingresa el ID de la cuenta que haras el retiro\n");
	scanf("%d",&id);
	ff=fopen(dir_cuen,"rb");
	while(!(fread(&id,sizeof(int),1, ff))){
			printf("Error en el ID de la cuenta a depositar\nIntente de nuevo\n");
			scanf("%d",&id);
		}
	fclose(ff);
	transac retiro;
	strcpy(retiro.tipo_mov,"Retiro\n");
	printf("¿Cuánto deseas retirar?\n");
	scanf("%d",&cantidad);

	ff=fopen(dir_cuen,"r+b");
	cuenta temp;
	fseek(ff,sizeof(int),SEEK_SET);
	while(fread(&temp,sizeof(cuenta),1,ff)==1){
		if(temp.id_cuenta==id){
			if(temp.saldo>=cantidad){
				temp.saldo-=cantidad;
				fseek(ff,-sizeof(cuenta),SEEK_SET);
				fwrite(&temp,sizeof(cuenta),1,ff);
			}
			else
				printf("Saldo insuficiente\n");
		}
	}
	fclose(ff);
}
void imprimirTransfe(FILE *d, FILE *ff){
	int x;
	int id_cli;

	d=fopen(dir_trans,"rb");
	ff=fopen(dir_cuen,"rb");
	fread(&id_cli,sizeof(int),1, d);
	fread(&x, sizeof(int), 1, ff);
	transac tran_1;
	cuenta cuen;
	printf("%-20s %-20s %-20s %-20s %-20s %-20s\n","ID.Transacción", "Tipo de transacción", "ID.Cuenta de origen", "ID.Cuenta de destino", "Fecha de la operación","Cantidad de la operación");
	while(fread(&cuen,sizeof(cuenta),1,ff)==1){
		fread(&tran_1,sizeof(transac),1,d);
		printf("%-20d %-20s %-20d %-20d   %02d/%02d/%d %-20d\n",tran_1.id_trans,tran_1.tipo_mov,tran_1.cuenta_or,tran_1.cuenta_des,tran_1.ff.dia,tran_1.ff.mes,tran_1.ff.anio, tran_1.cantidad);
	}
	fclose(ff);
	fclose(d);
}
