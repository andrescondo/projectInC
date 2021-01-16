#include <stdio.h>// para printf y scanf
#include <conio.h>//para usar gets
#include <ctype.h> // Para isalpha
#include <windows.h>// para todo system
#include <locale.h> //para usar caracteres especiales

//== VARIABLES CONSTANTES
#define PHC 14.50
#define PHN 14.80

//== VARIABLES GLOBALES
char line[]="\n====================================\n";

//=== Registros ===
struct dates {
	char name[100];
	char lastname[100];
	char ci[10];
	char address[200];
	char cell[10];
	char email[100];
}dt;

//== Funciones ==
int teacherInfo();
int contractData();
int nominationBuy();
int validation();
int viewInfo(float salary);


int main () {
	setlocale(LC_ALL, "spanish");
	int men=0;
	system("color 0a");
	
	menu:
		printf("%s**Sistema de pago**\n\n1.- Datos del Docente\n2.- Datos por Contrato\n3.- Pago del Nombramiento\n4.- Salir\n\tOpcion:  ",line);
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
			contractData();
			system("pause");
			system("cls");
			goto menu;
		case 3:
			nominationBuy();
			system("pause");
			system("cls");
			goto menu;
		case 4:
			break;
		default: goto menu;
			
	};

	getch();
	return 0;
};

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

int teacherInfo() {
	printf("%sIngrese los Datos del docente\n\n", line);
	do{
		printf("Ingrese el número de cédula del Docente\n"); 
		gets(dt.ci);
	} while( strlen(dt.ci) != 10 );
	do {
		printf("Ingrese Los Nombres del Docente: \n");
		gets(dt.name);
	} while(!validation(dt.name));
	do {
		printf("Ingresa los Apellidos del Docente: \n");
		gets(dt.lastname);
	} while(!validation(dt.lastname));
	printf("Ingrese la dirección del docente\n");
	gets(dt.address);
	printf("Ingrese el correo del docente\n");
	gets(dt.email);
	do {
		printf("Ingresa el número telefonico del Docente: \n");
		gets(dt.cell);
	} while(strlen(dt.cell) != 10);
	
};

int contractData(){
	int h=0;
	float fee=0, d=11.45,subTotal=0 , aditional=0.13, total=0;
	do {
		printf("Ingrese las horas trabajadas en el mes:\n");
		scanf("%d", &h);
		fflush(stdin);
	}while(h < 0);
	fee = h * PHC;
	subTotal= (fee * 11.45) / 100;
	if ( h > 160 ){
		total = (subTotal * aditional) + subTotal;
	} else {
		total = subTotal;
	};
	
	viewInfo(total);
};

int viewInfo (float salary) {
	printf(line);
	printf("Nombres del Docente: %s\n", dt.name);
	printf("Apellidos del Docente: %s \n" , dt.lastname);
	printf("Número de cédula del Docente: %s \n", dt.ci);
	printf("Correo Electronico: %s \n", dt.email);  
	printf("Número de telefono: %s \n", dt.cell);
	printf("Dirección Domiciliaria %s\n", dt.address);
	printf("Sueldo: %.2f", salary);
	printf(line);
}

int nominationBuy(){
};
