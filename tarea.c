#include <stdio.h>
#include <stdlib.h>

 char * descomprimir (char *nbreArchivo){ /*nombre: archivo.txt*/
 	int n;/*primer valor, cantidad de valores*/
 	FILE *arch=fopen("archivo.txt","r");
 	fread(&n,sizeof(int),1,arch);
 	unsigned int Repeticiones[n];
 	fread(Repeticiones,sizeof(unsigned int),n,arch);/**/
 	unsigned char Letras[n];
 	fread(Letras,sizeof(unsigned char),n,arch);
 	int largo = 0;
 	for (i=0; i<n; i++){
 		largo+=Repeticiones[i];
 	}
 	char *string;
 	string=(char *)malloc(largo+1)
 	if (string==NULL){
 		printf("No hay memoria\n");
 		exit(1);
 	}
 	int k=0


 	free(*string);
 	fclose(arch);
 }