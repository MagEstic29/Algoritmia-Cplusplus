#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<time.h>

using namespace std;

void limpiarArreglo(int arreglo[], int tam){
	for(int i=0; i<tam; i++){
		arreglo[i]= 0;
	}
}

void generarAleatorios(int arreglo[],int tam){
	srand(time(NULL));
	for(int i=0; i<tam; i++){
		arreglo[i]= (rand()%10)+1;
	}
}

int calcularModal(int arreglo[], int tam){
	int contador=0;
	int auxiliar[tam];
	//Hacemos copia de arreglo
	for(int i=0; i<tam; i++){
		auxiliar[i]= arreglo[i];
	}
	//Recabamos numeros
	for(int i=0; i<tam; i++){
		if(auxiliar[i]!=0){
			for(int j=i; j<tam; j++){
				if(j!=i){
					if(auxiliar[i]==auxiliar[j]){
						auxiliar[j]=0;
						contador++;
					}
				}
			}
		}
	}
	//Creamos el nuevo arreglo con numeros recabados
	int auxiliar2[tam-contador];
	for(int i=0,j=0; i<tam; i++){
		if(auxiliar[i]!=0){
			auxiliar2[j]= auxiliar[i];
			j++;
		}
	}
	//Se crea el arreglo que guardara los contadores
	int contadores[tam-contador];
	limpiarArreglo(contadores, tam-contador);
	//Verificaremos las coincidencias
	for(int i=0; i<tam-contador; i++){
		for(int j=0; j<tam; j++){
			if(auxiliar2[i]==arreglo[j]){
				contadores[i]++;
			}
		}
	}
	//Calculamos modal
	int maxValue= contadores[0];
	for(int i=0; i<tam-contador; i++){
		if(contadores[i]>maxValue){
			maxValue= contadores[i];
		}
	}
	//Imprimimos respuesta
	cout<<"\n\nEl modal es: ";
	for(int i=0, j=0; i<tam-contador; i++){
		if(contadores[i]==maxValue){
			if(j>0){
				cout<<" o "<<auxiliar[i];
			}
			else{
				cout<<auxiliar2[i];
				j++;
			}
		}
	}
}

int main(){
	int tam;
	cout<<"Ingrese el numero de elementos: ";
	cin>>tam;
	int arreglo[tam];
	system("cls");
	limpiarArreglo(arreglo, tam);
	generarAleatorios(arreglo, tam);
	//Imprimir arreglo
	for(int i=0; i<tam; i++){
		cout<<arreglo[i]<<"  ";
	}
	calcularModal(arreglo, tam);
	cout<<"\n\nCreado por Jonathan Ivan (Oso) (MagEstic29), todos los derechos reservados.";
}


