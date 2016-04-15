//
// Created by jp on 14-04-16.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(char *Str1, char * Str2, int corto, int *pos_dif){
    int half = corto/2;
    if (half == 0){
        if (Str1[0] == Str2[0]){
            return 0;
        }
        else{
            *pos_dif = 0;
            return 1;
        }
    }
    if (Str1[half] != Str2[half]){
        *pos_dif = half;
    }
    if (comparacion){
        compare(Str1, Str2, half, pos_dif);
    }
    if (*pos_dif == -1 && half>1){
        half += half/2;
        compare(Str1, Str2, half, pos_dif);
    }
}

int main(){
    char *pal1 = "hola";
    char *pal2 = "holgura";
    int min;
    if (strlen(pal1)<strlen(pal2)){
        min = strlen(pal1);
    }
    else{
        min = strlen(pal2);
    }
    int pos = -1;
    int dif = compare(pal1, pal2, min, &pos);
    printf("Son dif?: %d en %d\n", dif, pos);
}