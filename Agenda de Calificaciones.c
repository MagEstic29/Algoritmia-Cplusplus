#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int a,b,p,i,j,q,bandera,calif;
	char cadena[' '];
	char nombre_reg[' '];
	char nombre_arc[' '];
	char inicio[]={"Nombre\t\t\t\t\tCalif.\n\n"};
	FILE *archivo;
	system("color B");
	printf("****Programa de estructura de datos****\n\n");
	
	//Menu Principal
	printf("**[MENU]**\n\n");
	printf("1) Crear Archivo Nuevo\n2) Cargar Archivo\n\nElige el numero de la opcion: ");
	scanf("%i",&p);
	system("cls");
	
	switch (p){
		case 1:
			bandera=1;
			while(bandera!=0){
				printf("[Crear Archivo]\n\n");
				printf("Nombre de archivo con .extencion del archivo: ");
				scanf("%s",&nombre_arc);
				archivo= fopen(nombre_arc,"w");
				if(archivo!=NULL){
					bandera=0;
					fputs(inicio,archivo);
				}
				else{
					printf("\n\nError al crear archivo por favor intente de nuevo...\n\n");
					system("pause");
					system("cls");
				}
			}
			fclose(archivo);
			archivo= fopen(nombre_arc,"r+");
		break;
		
		case 2:
			bandera=1;
			while(bandera!=0){
				printf("[Cargar Archivo]\n\n");
				printf("Introduzca el nombre del archivo con .extencion del archivo: ");
				scanf("%s",&nombre_arc);
				archivo= fopen(nombre_arc,"r+");
				if(archivo!=NULL){
					bandera=0;
					printf("\n\n!!Archivo Cargado y Listo para Usar!!\n\n");
					system("pause");
				}
				else{
					printf("\n\nError al cargar archivo por favor intente de nuevo...\n\n");
					system("pause");
					system("cls");
				}
			}
		break;
		
		default:
			return 1;
		break;
		
	//Fin de Switch inicial
	}
	bandera=1;
	while(bandera!=0){
	Menu();
	scanf("%i",&q);
	
	switch (q){
		case 1:
			system("cls");
			fclose(archivo);
			archivo= fopen(nombre_arc,"a");
			printf("Introduce el registro a agregar, Recuerda poner '_' como separador: ");
			scanf("%s",&nombre_reg);
			printf("Calificacion: ");
			scanf("%i",&calif);
			sprintf(cadena,"%s\t\t%i\n",nombre_reg,calif);
			fputs(cadena,archivo);
			fclose(archivo);
			archivo= fopen(nombre_arc,"r+");
		break;
		
		case 2:
		
		break;
		
		case 3:
			bandera=1;
			fclose(archivo);
			archivo= fopen(nombre_arc,"r");
			system("cls");
			printf("\nEl contenido del archivo es:\n\n");
 			while (feof(archivo) == 0){
 				fgets(cadena,100,archivo);
 				printf("%s",cadena);
 				}
 				printf("\n\n");
        	system("PAUSE");
		break;
		
		default:
			fclose(archivo);
			bandera=0;
		break;
		
	//Fin de Switch secundario
	}
	}
	
	fclose(archivo);
	return 0;
}

int Menu(){
	system("cls");
printf("**[Menu]**\n\n\n1) Agregar Registro\n2) Borrar Registro\n3) Mostrar Registros\n4) Salir\n\nElige el numero de la opcion: ");
}
