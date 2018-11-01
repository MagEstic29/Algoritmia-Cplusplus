#include<iostream>
#include<cstdlib>
#include<time.h>


using namespace std;

int main(){
	int n;
	float tiempo;
	srand(time(NULL));
	clock_t inicio,final;
	
	inicio=clock();
	
	cout<<"Hola\n\n"; system("pause"); system("cls");
	
	cout<<"[Generador de numeros Aleatorios Negativos]"<<endl<<endl;
	for(int i=0;i<20;i++){
		n= 1+rand()%10;
		n=n*-1;
		cout<<n<<"  ";
	}
	
	cout<<"\n\n[Generador de numeros Aleatorios Positivo]"<<endl<<endl;
	for(int i=0;i<20;i++){
		n= 1+rand()%10;
		cout<<n<<"  ";
	}
	
	final=clock();
	
	tiempo= final-inicio;
	cout<<"\n\nSe tardo "<<tiempo/CLK_TCK<<" segundos"<<endl;
	cout<<"\n\nSe tardo "<<tiempo/CLK_TCK/1000<<" segundos"<<endl;
	cout<<"\n\nSe tardo "<<1000L*tiempo/CLK_TCK<<" milisegundos"<<endl;
	
	return 0;
}
