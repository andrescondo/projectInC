#include <stdio.h>// para printf y scanf
#include <conio.h>//para usar gets
#include <windows.h>// para todo system
#include <locale.h> //para usar caracteres especiales
#include <string.h>

#include "library/validation.h"//validacion de letras

//== CONSTANTES
#define PHC 14.50
#define PHN 15.80

//== VARIABLES GLOBALES
char line[]="\n=================================================\n", 
	email[]="",ci[]="";
// == ESTRUCTURAS	
struct info{
	char address[40];
	char dni[10];
	
};

struct teacher{
	char name[20];
	char lastname[30];
	char cell[10];
	char mail[30];
	struct info i; //estructura anidadas
};

//== Funciones ==
//int validation(); AHORA ES UNA LIBRARY
int teacherInfo(struct teacher *t);
int contract(float d,float aditional );
void viewInfo(float salary, float subTotal, float vExtras, int hExtras,int h, struct teacher *t);
struct teacher te;

//Funcion principal
int main () {
	setlocale(LC_ALL, "spanish");//Para usar alfabeto en español
	int men=0; 
	float d=0, aditional=0;
	system("color 0a");
	
	//Inicializaci�n en cero
	strcpy(te.name,"");
	strcpy(te.lastname,"");
	strcpy(te.cell,"");
	strcpy(te.i.address,"");
	strcpy(te.mail,"");
	strcpy(te.i.dni,"");

	menu:			
		printf("%s**Sistema de pago**\n\n1.- Datos del Docente\n2.- Datos por Contrato\n3.- Datos por Nomina\n4 .- Salir\n\tOpcion:  ",line);
		scanf("%d", &men);
		fflush(stdin);
		system("cls");
		
	switch(men) {
		case 1:
			teacherInfo(&te);
			system("pause");
			system("cls");
			goto menu;
		case 2:
			d=0.1145; 
			aditional=0.13;
			contract(d, aditional);
			system("pause");
			system("cls");
			goto menu;
		case 3:
			d=0.1015;
			aditional=0.15;
			contract(d, aditional);
			system("pause");
			system("cls");
			goto menu;
		case 4:
			printf("Pulse un Botón para cerrar el programa...");
			break;
			
		default: goto menu;
			
	};

	getch();
	return 0;
};

//funcion para ingresar datos del docente
int teacherInfo(struct teacher *t) {
	char warning[] = "==Ingresar Datos y no dejar en blanco==\a\n",
	 warning2[]="==Son 10 digitos a ingresar==\a\n", // \a sirve para dar una alerta 
	 warning3[] = "==Solo se aceptan letras==\a\n",
	 warning4[] = "==Solo se aceptan Números==\a\n";

	printf("%sIngrese los Datos del docente\n\n", line);
	do{
		printf("\nIngrese el número de cúdula del Docente\n"); 
		fflush(stdin);
		gets(t->i.dni);
		if(strlen(t->i.dni) != 10){
			printf(warning2);
		};
		if( validation(t->i.dni)){
			printf(warning4);
		}
		strcpy(ci, t->i.dni);
		
	} while( validation(t->i.dni) && strlen(t->i.dni) != 10 );//valida que tenga 10 digitos
	
	do {
		printf("\nIngrese Los Nombres del Docente: \n");
		fflush(stdin);
		gets(t->name);
		if(!validation(t->name)){
			printf(warning3);
		};
		if (strlen(t->name) == 0){
			printf(warning);
		};
	} while(!validation(t->name) || strlen(t->name) == 0);//valida que solo se ingresen letras
	
	do {
		printf("\nIngresa los Apellidos del Docente: \n");
		fflush(stdin);
		gets(t->lastname);
		if(!validation(t->lastname)){
			printf(warning3);
		};
		if (strlen(t->lastname) == 0){
			printf(warning);
		};
	} while(!validation(t->lastname) || strlen(t->lastname) == 0);//valida que solo se ingresen letras
	
	do{
		printf("\nIngrese la dirección del docente\n");
		fflush(stdin);
		gets(t->i.address);
		if(strlen(t->i.address) == 0){
			printf(warning);
		};
	} while ( strlen(t->i.address) == 0);
	
	do{
		printf("\nIngrese el correo del docente\n");
		fflush(stdin);
		gets(t->mail);
		if(strlen(t->mail) == 0){
			printf(warning);
		};
		strcpy(email, t->mail);
	} while ( strlen(t->mail) == 0);
	
	
	do {
		printf("\nIngresa el número telefonico del Docente: \n");
		fflush(stdin);
		gets(t->cell);
		if(strlen(t->cell) != 10){
			printf(warning2);
		};
		if(validation(t->cell)){
			printf(warning4);
		};
	} while(validation(t->cell) || strlen(t->cell) != 10);//valida que solo se ingresen 10 digitos
	
};

//funcion de calculo del docente por contrato
int contract(float d, float aditional){ //descuento adicional	
	int h=0, hExtras=0;
	float fee=0,subTotal=0, total=0, vExtras=0; // tarifa	
	do {
		printf("%s Ingrese las horas trabajadas en el mes:  ",line);
		scanf("%d", &h);
		fflush(stdin);
	}while(h < 0);

	if ( h > 160 ){
		hExtras = h - 160;
		vExtras = ((hExtras * PHC) * aditional ) + (hExtras * PHC);
		fee = 160 * PHC;
		subTotal = vExtras + fee;
		total = subTotal - (subTotal * d);
	} else {
		hExtras = 0;
		vExtras = 0;
		fee = 160 * PHC;
		subTotal = vExtras + fee;
		total = subTotal - (subTotal * d);
	};
	system("cls");
	viewInfo(total, subTotal, vExtras, hExtras,h, &te);// llama los datos del docente y se le envie el valor del salario
};

//funcion para visualizar los datos del docente
void viewInfo (float salary, float subTotal, float vExtras, int hExtras,int h, struct teacher *t) {
	printf(line);
	printf("\t Datos del Docente\n\n");
	printf("Fecha de facturación: ");printf(__DATE__);
	printf("\n\nNombres y Apellidos del Docente: %s %s\n", t->name, t->lastname );
	printf("Número de cúdula del Docente:   %s\n",t->i.dni);
	printf("Correo Electronico: \t\t %s\n", email);
	printf("Número de telefono: \t\t %s \n", t->cell);
	printf("Dirección Domiciliaria: \t %s\n", t->i.address);
	printf(line);
	printf("Horas Trabajadas: \t%d\n",h);
	if ( hExtras > 0){
		printf("Horas extras: \t\t%d\n", hExtras);
		printf("Valor de horas Extras:  %.2f\n", vExtras);
	}
//	MessageBox("Hello","Caption",MB_OK);

	printf("SubTotal: \t\t%.2f\n", subTotal);
	printf("Sueldo:   \t\t%.2f", salary);
	printf(line);
};


