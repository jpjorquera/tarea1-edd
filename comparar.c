#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comparar(char *S1, char *S2, int menor, int base, char* prefix, int counter){
	int mitad = menor/2;					/*Caso base*/
	if (mitad == base) {
		if (S1[base] == S2[base]) {
			prefix[base] = S1[base];
			counter ++;
			return 1;
		}
	}
	if (comparar(S1, S2, mitad, base, prefix, counter)) {
		prefix[mitad/2] = S1[mitad/2];		/*Asignar valor en cada cuarto*/
		counter++;
	}
	else {
		return 0;
	}
	int adelante;
	adelante = menor*(3/4);
	if (comparar(S1, S2, adelante, menor/2, prefix, counter)){
		prefix[adelante/2] = S1[adelante/2];
	}
	return 0;
}

int main(){
	char *a = "Holgura";
	char *b = "Hola";
	int menor;
	if (strlen(a)<=strlen(b)){
		menor = strlen(a);
	}
	else {
		menor = strlen(b);
	}
	char *prefijo = (char *)malloc(sizeof(char)*menor);
	comparar(a, b, menor, 0, prefijo, 0);
	printf("El prefijo es: %s", prefijo);
	return 0;
}
