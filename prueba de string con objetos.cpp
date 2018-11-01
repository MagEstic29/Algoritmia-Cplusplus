#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

class nodo{
	public:
		int boleta;
		int edad;
		string nombre;
		nodo *sig;
		nodo *ant;
};

typedef nodo *pnodo;

class lista{
	public:
		int Inserta_fin(int a,int e, string n);
		int Muestra (void);
		int Guarda(void);
		int Recupera(void);
		lista(){inicial= NULL; aux= NULL; aux2=NULL; aux3=NULL; aux4=NULL;}
		pnodo inicial, aux, aux2,aux3,aux4;
};

lista::Inserta_fin(int a,int e, string n){
	
	aux= new(nodo);
	aux->boleta=a;
	aux->edad=e;
	aux->nombre=n;
	if(inicial==NULL){
		aux->sig= NULL;
		aux->ant=NULL;
		inicial= aux;
		aux2=inicial;
	}
	else{
		aux2->sig=aux;
		aux->sig=NULL;
		aux->ant=aux2;
		aux2=aux;
	}
}

lista::Muestra(){
	if(inicial==NULL){
		cout<<"** LISTA VACIA **";
	}
	else{
		aux=inicial;
		do{
			cout<<aux->boleta<<"\t"<<aux->nombre<<"\t"<<aux->edad<<endl;
			aux=aux->sig;
		}while(aux!=NULL);
	}
}

lista::Guarda(){
	if(inicial==NULL){
		cout<<"** LISTA VACIA **";
	}
	else{
		FILE *archivo;
		char *cadena2= (char*)calloc(70,sizeof(string));
		archivo= fopen("Lista de Alumnos.csv","w");
		sprintf(cadena2,"No. Boleta , Nombre del Alumno ,,Edad\n\n");
		fputs(cadena2,archivo);
		
		aux=inicial; int bandera=0;
		while(bandera!=1){
			
			if(aux!=aux2){
				sprintf(cadena2,"%i,%s,,%i\n",aux->boleta,aux->nombre.c_str(),aux->edad);
				fputs(cadena2,archivo);
				aux=aux->sig;
			}
			else{
				sprintf(cadena2,"%i,%s,,%i\n",aux->boleta,aux->nombre.c_str(),aux->edad);
				fputs(cadena2,archivo);
				bandera=1;
			}
			
		}
		cout<<"** ARCHIVO GUARDADO **";
		fclose(archivo);
	}
}

lista::Recupera(){
	FILE *archivo;
	archivo= fopen("Lista de Alumnos.csv","r");
	if(!archivo){
		cout<<"** ARCHIVO NO ENCONTRADO **";
	}
	else{
		cout<<"** ARCHIVO ENCONTRADO **";
	}
}

void Menu(){
	cout<<"\n\t** LISTA DINAMICA **"<<endl<<endl;
	cout<<"(1) Insertar Elemento"<<endl;
	cout<<"(2) Mostrar Lista"<<endl;
	cout<<"(3) Guardar Lista"<<endl;
	cout<<"(4) Recuperar Lista"<<endl;
	cout<<"(5) Salir"<<endl<<endl;
	cout<<"ELIJA UNA OPCION: ";
}

int main(){
	system("color B");
	int op,a,ord_asc=0,ord_des=0, x,e;
	char cadena[60];
	
	lista p;
	
	do{
		Menu();  cin>>op;
		system("cls");
		
		switch (op){
			
			case 1:
			cout<<"[INSERTAR ELEMENTO]"<<endl<<endl;
				cout<<"INTRODUZCA LA BOLETA: "; cin>>a;
				cout<<"INTRODUZCA LA EDAD: "; cin>>e;
				cin.get();
				cout<<"INTRODUZCA EL NOMBRE: "; cin.getline(cadena,60,'\n');
				p.Inserta_fin(a,e,cadena);
				cout<<"\n** ELEMENTO AGREGADO **";
				ord_asc=0;
				ord_des=0;
				
				break;
				
			case 2:
				cout<<"[MOSTRAR LISTA]"<<endl<<endl;
				cout<<"No. Boleta\tNombre\t\tEdad"<<endl<<endl;
				p.Muestra();
				
				break;
				
			case 3:
				cout<<"[GUARDAR A ARCHIVO]"<<endl<<endl;
				p.Guarda();
				
				break;
			
			case 4:
				cout<<"[RECUPERA ARCHIVO]"<<endl<<endl;
				p.Recupera();
				
				break;
					
				//Fin de Switch		
		}
		
		cout<<endl<<endl<<"---------------------------------"<<endl;
		system("pause");  system("cls");

	}while(op!=5);
	
	
	return 0;
}
