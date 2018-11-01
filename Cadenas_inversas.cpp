//Autor: Ramos Diaz Enrique
//Practica --
//Fecha. 28 de Octubre 2016

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

char invertir(char *cadena, int len)
{
	
	char invertida;
	char *cadena1 = (char*)calloc(len, sizeof(char));
	strcpy(cadena1, cadena);
	int i=0,j=0;
		
		
		for (i=0,j=len-1; i<len/2; i++,j--)
		{
			invertida=cadena1[i];
			cadena1[i]=cadena1[j];
			cadena1[j]=invertida;
		}
		
		
		
		printf("\n\nLa cadena invertida es: \n%s \n\n", cadena1);
	
	
}


void mayus_minus(char *cadena, int len)
{
	int op, i, j;
	char *ascii = (char*)calloc(len, sizeof(char));
	strcpy(ascii, cadena);
	printf ("\n\n\tMENU:\n");
	printf("\t1.- Minusculas\n");
	printf("\t2.- Mayusculas\n");
	scanf("\t%d", &op);
	
	switch (op)
	{
		case 1:
			printf("\nLa cadena en minusculas es:\n");
			for (i=0; i<len; i++)
			{
				
				if(ascii[i]>=65 && ascii[i]<=90)
				{
					ascii[i]+=32;
				
				}
			
				printf("%c", ascii[i]);
			}
			printf("\n\n");
		break;
		
		case 2:
		printf("\nLa cadena en mayusculas es:\n");
				
			for (i=0; i<len; i++)
			{
				
			
				if(ascii[i]>=97 && ascii[i]<=122)
				{
					ascii[i]-=32;
					
				}
			printf("%c", ascii[i]);
			
			}
				
				printf("\n\n");
		break;
	}
	
	

}

int main(void)
{
	
	char *cadena = (char*)calloc(40000, sizeof(char));

	
	int len;



	
	printf("CADENA: \n");
	gets(cadena);
	
	len = strlen(cadena);
	
	invertir(cadena, len);
	mayus_minus(cadena, len);
	

	

	

	
			
	return 1;
	
}
