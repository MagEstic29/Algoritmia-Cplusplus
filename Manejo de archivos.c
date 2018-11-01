#include<stdio.h>

int main(void){
	int entero=5;
	float decimal=6.25;
	char caracter='c';
	char cad1[]={"Hola a todos"};
	char cadd[60];
	
	FILE *apu_archivo;
	apu_archivo= fopen("archivo01.txt","w");
	if(apu_archivo!=NULL){
		fputs("Ejemplo 1\n",apu_archivo);
		fputs("Ejemplo 2\t 3 4",apu_archivo);
		sprintf(cadd,"\t*** %d - %.1f \n %c \t %s",entero,decimal,caracter,cad1);
		fputs(cadd,apu_archivo);
		fclose(apu_archivo);
		printf("Archivo creado y abierto:\n\n");
	}
	int c;
	
	apu_archivo=fopen("archivo01.txt","r");
	if(apu_archivo!=NULL){
		do{
			c= fgetc(apu_archivo);
			printf("%c",c);
		}while(c!=EOF);
		fclose(apu_archivo);
	}
	
	return 0;
}
