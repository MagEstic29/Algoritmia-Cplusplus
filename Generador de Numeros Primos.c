#include<stdio.h>
#include<stdlib.h>

int main(){
	system("color B");
	int a,b=0,c,i,j;
	FILE *archivo;
	char cadena[100];
	
	printf("***Programa Generador de numeros Primos***\n\n");
	printf("Hasta que numero desea generar?: ");
	scanf("%i",&a);
	
	archivo= fopen("Primos Generados.txt","w");
	fprintf(archivo,"Numeros Primos Generados: \n\n");
	
	for(i=1;i<=a;i++){
		b=0;
		for(j=1;j<=i;j++){
		if(i%j==0){
			b++;
		}
	}
	if(b==2){
		if(i!=a){
			sprintf(cadena,"%i, ",i);
			fputs(cadena,archivo);
		}
		else{
			sprintf(cadena,"%i. ",i);
			fputs(cadena,archivo);
		}
	}
	}
	sprintf(cadena,"Fin.");
	fputs(cadena,archivo);
	printf("\n\nCreando Archivo...\n\n\n");
	system("pause");
	system("cls");
	
	if(archivo!=NULL){
		printf("!Archivo Creado!\n\n");
	}
	else{
		printf("Error al crear, intentelo de nuevo\n\n");
	}
	
	fclose(archivo);
	
	
	return 0;
}
