//
// Created by jp on 14-04-16.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int diferentes(char *Str1, char * Str2, int largo, int *pos_dif) {      //comparar 2 strings y guardar la pos en que son diferentes
    int half = largo / 2;
    if (Str1[half] != Str2[half]) {                                     //buscar diferencia en mitad
        *pos_dif = half;
    }
    if (largo == 1) {                                                   //case base
        if (Str1[0] != Str2[0]) {
            *pos_dif = 0;
            return 1;
        }
        else {
            return 0;
        }
    }
    if (diferentes(Str1, Str2, half, pos_dif) == 0) {                   //comparar recursivamente en cada mitad
        int i;                                                          //de no encontrar, buscar en mitad de adelante
        for (i = half+1; i < largo; i++) {
            if (Str1[i] != Str2[i]) {                                   //encontro distinto
                *pos_dif = i;
                return 1;
            }
        }
        if (*pos_dif == largo){                                         //comprobar si hay distinto encontrado en comparacion de mitades
            return 1;
        }
        return 0;
    }
}

int main(){
    char *pal1 = "esternocleidomastoideo";
    char *pal2 = "esternon";
    int min;
    if (strlen(pal1)<strlen(pal2)){
        min = strlen(pal1);
    }
    else{
        min = strlen(pal2);
    }
    int pos = -1;
    int dif = diferentes(pal1, pal2, min, &pos);
    char *verdad;
    if (dif){
        verdad="True";
    }
    else{
        verdad="False";
    }
    printf("Son dif?: '%s'; en posicion %d\n", verdad, pos);
}