#include <stdio.h>
#include <string.h>

/*****
*	int diferentes
******
*	busca encontrar la posicion en la que dos strings se diferencian
******
*	Input:
*		char * Str1 : Primer String a comparar
*		char * Str2 : Segundo String a comparar
*		int largo : tamano del String mas corto
*		int * tam_dif : almacena valor del tamano en que se diferencian
******
*	Returns:
*		int, devuelve si se ha encontrado o no alguna diferencia
*****/

int diferentes(char *Str1, char * Str2, int largo, int *tam_dif) {
    int half = largo / 2;
    if (Str1[half] != Str2[half]) {                                     //buscar diferencia en mitad
        *tam_dif = half;
    }
    if (largo == 1) {                                                   //case base
        if (Str1[0] != Str2[0]) {
            *tam_dif = 0;
            return 1;
        }
        else {
            return 0;
        }
    }
    if (diferentes(Str1, Str2, half, tam_dif) == 0) {                   //comparar recursivamente en cada mitad
        int i;                                                          //de no encontrar, buscar en mitad de adelante
        for (i = half+1; i < largo; i++) {
            if (Str1[i] != Str2[i]) {                                   //encontro distinto
                *tam_dif = i;
                return 1;
            }
        }
        if (*tam_dif == largo){                                         //comprobar si hay distinto encontrado en comparacion de mitades
            return 1;
        }
        return 0;
    }
}
