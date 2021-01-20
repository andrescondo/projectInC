#include <stdio.h>// para printf y scanf
#include <conio.h>//para usar gets
#include <ctype.h> // Para isalpha
#include <windows.h>// para todo system
#include <locale.h> //para usar caracteres especiales
#include <string.h> //para usar strings

//== VARIABLES CONSTANTES
#define PHC 14.50
#define PHN 14.80

//== VARIABLES GLOBALES
char line[]="\n============================================\n",
	name[30]="", lastname[30]="", dni[10]="", 
	direction[30]="", cell[10]="", email[30]="";

//== Funciones ==
int teacherInfo();
int contract(float d,float aditional);
int validation();
int viewInfo(float salary, float subTotal);

//Funcion principal
int main () {
	setlocale(LC_ALL, "spanish");//Para usar alfabeto en español
	int men=0; 
	float d=0, aditional=0;
	system("color 0a");
	
	menu:
		printf("%s**Sistema de pago**\n\n1.- Datos del Docente\n2.- Datos por Contrato\n3.- Datos por Nomina\n4 .- Salir\n\tOpcion:  ",line);
		scanf("%d", &men);
		fflush(stdin);
		system("cls");
		
	switch(men) {
		case 1:
			teacherInfo();
			system("pause");
			system("cls");
			goto menu;
		case 2:
			d=11.45; 
			aditional=0.13;
			contract(d, aditional);
			system("pause");
			system("cls");
			goto menu;
		case 3:
			d=10.15;
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

//validación si lo ingresado son letras 
int validation(char letters[]){
	int i=0;
	while ( letters[i]) {
		if ( !isalpha(letters[i])  && letters[i] != ' ') {
			return 0;
		}
		i++;
	};
	return 1;
	
};

//funcion para ingresar datos del docente
int teacherInfo() {
	char warning[] = "==Ingresar Datos y no dejar en blanco==\n",
	 warning2[]="==Son 10 digitos a ingresar==\n",
	 warning3[] = "==Solo se aceptan letras==\n";

	printf("%sIngrese los Datos del docente\n\n", line);
	do{
		printf("Ingrese el número de cédula del Docente\n"); 
		gets(dni);
		if(strlen(dni) != 10){
			printf(warning2);
		};
		fflush(stdin);
	} while( strlen(dni) != 10 );//valida que tenga 10 digitos
	do {
		printf("Ingrese Los Nombres del Docente: \n");
		gets(name);
		fflush(stdin);
		if(!validation(name)){
			printf(warning3);
		};
		if (strlen(name) == 0){
			printf(warning);
		};
	} while(!validation(name) || strlen(name) == 0);//valida que solo se ingresen letras
	
	
	do {
		printf("Ingresa los Apellidos del Docente: \n");
		gets(lastname);
		fflush(stdin);
		if(!validation(lastname)){
			printf(warning3);
		};
		if (strlen(lastname) == 0){
			printf(warning);
		};
	} while(!validation(lastname) || strlen(lastname) == 0);//valida que solo se ingresen letras
	do{
		printf("Ingrese la dirección del docente\n");
		gets(direction);
		if(strlen(direction) == 0){
			printf(warning);
		};
	} while ( strlen(direction) == 0);
	
	do{
		printf("Ingrese el correo del docente\n");
		gets(email);
		if(strlen(email) == 0){
			printf(warning);
		};
		fflush(stdin);
	} while ( strlen(email) == 0);	
	
	do {
		printf("Ingresa el número telefonico del Docente: \n");
		gets(cell);
		if(strlen(cell) != 10){
			printf(warning2);
		};
		fflush(stdin);
	} while(strlen(cell) != 10);//valida que solo se ingresen 10 digitos

};

//funcion de calculo del docente por contrato
int contract(float d, float aditional){
	int h=0;
	float fee=0,subTotal=0, total=0;
	do {
		printf("%s Ingrese las horas trabajadas en el mes:\n",line);
		scanf("%d", &h);
		fflush(stdin);
	}while(h < 0);
	fee = h * PHC;
	subTotal= fee - ((fee * d) / 100 );
	if ( h > 160 ){
		total = (subTotal * aditional) + subTotal;
	} else {
		total = subTotal;
	};
	system("cls");
	viewInfo(total, subTotal);// llama los datos del docente y se le envie el valor del salario
};

//funcion para visualizar los datos del docente
int viewInfo (float salary, float subTotal) {
	printf(line);
	printf("\t Datos del Docente\n\n");
	printf("Nombres y Apellidos del Docente: %s %s\n", name, lastname);
	printf("Número de cédula del Docente: %s \n", dni);
	printf("Correo Electronico: %s \n", email);  
	printf("Número de telefono: %s \n", cell);
	printf("Dirección Domiciliaria: %s\n", direction);
	printf(line);
	printf("SubTotal: %.2f\n", subTotal);
	printf("Sueldo:   %.2f", salary);
	printf(line);
};

