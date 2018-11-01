#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	system("color B");
	remove("Matriz Generada.csv");
	srand(time(NULL));
	int a,b,c,i,j,bandera,t;
	int **matriz;
	char cadena[100];
	FILE *archivo;
	archivo= fopen("Matriz Generada.csv","w");
	printf("Defina el numero de ecuaciones: ");
	scanf("%i",&a);
	b=a+1;
	printf("\n");
	//Genera Matriz
	matriz= (int**)malloc(a*sizeof(int*));
	for(i=0;i<b;i++){
		matriz[i]=(int*)calloc(b,sizeof(int));
	}

	if(a<15){
	//Imprimir matriz en pantalla
	for(i=0;i<a;i++){
		for(j=0;j<b;j++){
			if(j==b-1){
				printf("| %i",matriz[i][j]);
			}
			else{
				printf("%i\t",matriz[i][j]);
			}
		}
		printf("\n");
	}
	}
	
	//Dar valores a matriz
	for(i=0;i<a;i++){
		for(j=0;j<b;j++){
			bandera=1;
			while(bandera!=0){
				t=rand()%2;
				if(t==0){
					c=rand()%20;
				}
				else if(t==1){
					c=rand()%(10)-10;
				}
				if(c!=0 && c!=1 && c!=-1){
					bandera=0;
				}
			}
			matriz[i][j]=c;			
		}
	}
	
	//Imprimir matriz en archivo
	for(i=0;i<a;i++){
		for(j=0;j<b;j++){
			if(j==b-1){
				sprintf(cadena,"%i,",matriz[i][j]);
				fputs(cadena,archivo);
			}
			else{
				if(j>0){
					if(matriz[i][j]>0){
						sprintf(cadena,"+%ix,",matriz[i][j]);
						fputs(cadena,archivo);	
					}
					else{
						sprintf(cadena,"%ix,",matriz[i][j]);
						fputs(cadena,archivo);
					}
				}
				else{
					sprintf(cadena,"%ix,",matriz[i][j]);
					fputs(cadena,archivo);
				}
				
			}
		}
		sprintf(cadena,"\n");
		fputs(cadena,archivo);
	}
	printf("\n\nCreando archivo...\n\n");
	system("pause");
	system("cls");
	if(archivo!=NULL){
		system("cls");
		printf("!Archivo Creado!\n\n");
	}
	else{
		printf("Error al crear, intentelo mas tarde\n\n");
	}
	fclose(archivo);
	
	if(a<15){
		//Imprimir matriz en pantalla
		for(i=0;i<a;i++){
		for(j=0;j<b;j++){
			if(j==b-1){
				printf("| %i",matriz[i][j]);
			}
			else{
				printf("%i\t",matriz[i][j]);
			}
		}
		printf("\n");
	}
	}
	
	
	return 0;
}
