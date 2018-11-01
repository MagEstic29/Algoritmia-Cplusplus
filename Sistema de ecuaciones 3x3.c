/*
	Name: Sistema de ecuaciones de 3x3
	Author: Gutierrez Beltran Jonathan Ivan
	Date: 08/10/16 23:20
	Description: " "
*/



#include<stdio.h>

int main(){
	system("color B");
	float A[10][10], s=' ', x=' ', y=' ', z=' ',rein=1;
	printf("\t\t***Este programa soluciona un sistema de ecuaciones Ax+By+Cz=D***\n\n");

while(rein!=0){
	printf("Introduza valor de A: ");
	scanf("%f",&A[0][0]);
	printf("\nIntroduzca valor de B: ");
	scanf("%f",&A[0][1]);
	printf("\nIntroduzca valor de C: ");
	scanf("%f",&A[0][2]);
	printf("\nIntroduzca valor de D: ");
	scanf("%f",&A[0][3]);
	system("cls");
	
//Segunda ecuacion
	printf("Introduza valor de A: ");
	scanf("%f",&A[1][0]);
	printf("\nIntroduzca valor de B: ");
	scanf("%f",&A[1][1]);
	printf("\nIntroduzca valor de C: ");
	scanf("%f",&A[1][2]);
	printf("\nIntroduzca valor de D: ");
	scanf("%f",&A[1][3]);
	system("cls");
	
//Tercera ecuacion
	printf("Introduza valor de A: ");
	scanf("%f",&A[2][0]);
	printf("\nIntroduzca valor de B: ");
	scanf("%f",&A[2][1]);
	printf("\nIntroduzca valor de C: ");
	scanf("%f",&A[2][2]);
	printf("\nIntroduzca valor de D: ");
	scanf("%f",&A[2][3]);
	system("cls");

//Delta s	
s=((A[0][0]*A[1][1]*A[2][2])+(A[1][0]*A[2][1]*A[0][2])+(A[2][0]*A[0][1]*A[1][2]))-((A[0][2]*A[1][1]*A[2][0])+(A[1][2]*A[2][1]*A[0][0])+(A[2][2]*A[0][1]*A[1][0]));

//Delta x
x=((A[0][3]*A[1][1]*A[2][2])+(A[0][1]*A[1][2]*A[2][3])+(A[0][2]*A[1][3]*A[2][1]))-((A[0][2]*A[1][1]*A[2][3])+(A[0][3]*A[1][2]*A[2][1])+(A[0][1]*A[1][3]*A[2][2]));

//Delta y
y=((A[0][0]*A[1][3]*A[2][2])+(A[1][0]*A[2][3]*A[0][2])+(A[2][0]*A[0][3]*A[1][2]))-((A[0][2]*A[1][3]*A[2][0])+(A[1][2]*A[2][3]*A[0][0])+(A[2][2]*A[0][3]*A[1][0]));

	
//Delta z
z=((A[0][0]*A[1][1]*A[2][3])+(A[0][1]*A[1][3]*A[2][0])+(A[0][3]*A[1][0]*A[2][1]))-((A[0][3]*A[1][1]*A[2][0])+(A[0][0]*A[1][3]*A[2][1])+(A[0][1]*A[1][0]*A[2][3]));

	
//Valores
x=x/s;
printf("El valor de x es: %.1f",x);

y=y/s;
printf("\nEl valor de y es: %.1f",y);

z=z/s;
printf("\nEl valor de z es: %.1f",z);

//Reinicio
printf("\n\nDesea reiniciar el programa? 1= Si  0= No: ");
scanf("%f",&rein);
system("cls");

}

printf("!!Hasta Luego!!\n\n");

	return 0;
}
