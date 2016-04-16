#include <stdio.h>
#include <string.h>
#include "compare.c"

/*****
*   int pCML
******
*   Compara los prefijos entre strings para obtener el mas largo
******
*   Input:
*       char ** S : array de 'strings'
*       int n : cantidad de strings en S
******
*   Returns:
*       int, retorna el tamano del prefijo mas largo en comun de S
*****/

int pCML(char **S, int n){
    int i, j, mas_largo = 0, tam_menor, tam_pref;
    for (i=0; i<n; i++){                                            //Iterar para cada string
        tam_menor = strlen(S[i]);
        for (j=i+1; j<n; j++) {
            if (strlen(S[j]) < strlen(S[i])) {                      //Verificar string mas corto
                tam_menor = strlen(S[i + 1]);
            }
            if (diferentes(S[i], S[j], tam_menor, &tam_pref)) {     //Si son diferentes
                if (tam_pref > mas_largo) {
                    mas_largo = tam_pref;                           //Comparar con el ya almacenado
                }
            }
            else{                                                   //Si son iguales
                mas_largo = tam_menor;
            }
        }
    }
    return mas_largo;
}

int main (){
    char *prueba[7];
    prueba[0] = "hola";
    prueba[1] = "holgura";
    prueba[2] = "esternocleidomastoideo";
    prueba[3] = "esternon";
    prueba[4] = "abcdefghijklmnopqrstuvwxyz";
    prueba[5] = "estertor";
    prueba[6] = "ese";
    int prefix = pCML(prueba, 7);
    printf("El prefijo mas largo en comun es de tamano = %d \n", prefix);
    return 0;
}
