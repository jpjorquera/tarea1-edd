#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {            //Struct de iniciales
    char inicial;           // Letra inicial
    int repeticiones;       // Numero de veces que ha salido
    int *posiciones;        // Array de las posiciones con dicha inicial
}iniciales;

/*****
*   int pCML
******
*   Compara los prefijos entre strings para obtener el mas largo, primero busca todas las iniciales distintas almacena
*   ciertos parametros de cada inicial en un struct, para repetir el proceso recursivamente con las de igual inicial.
******
*   Input:
*       char ** S : array de 'strings'
*       int n : cantidad de strings en S
******
*   Returns:
*       int, retorna el tamano del prefijo mas largo en comun de S
*****/

int pCML(char **S, int n){
    int i, j, pos_vacia = 0, asignado;
    char inicial_actual;
    iniciales *auxiliar = calloc((size_t) n, sizeof(iniciales));
    for (i=0; i<n; i++){                                                            //Por cada string
        inicial_actual = S[i][0];
        asignado = 0;
        if (inicial_actual == '\0') {                                               //en caso de llegar al final de un string
            continue;
        }
        j=0;
        while (j < pos_vacia && !asignado) {                                        //buscar si ya se almaceno esa inicial
            if (inicial_actual == auxiliar[j].inicial) {                            //actualizar valores inicial
                auxiliar[j].posiciones[auxiliar[j].repeticiones++] = i;
                asignado = 1;
            }
            j++;
        }
        if (!asignado) {                                                            //asignar inicial por primera vez
            auxiliar[pos_vacia].inicial = inicial_actual;
            auxiliar[pos_vacia].repeticiones = 1;
            auxiliar[pos_vacia].posiciones = malloc(n*sizeof(int));
            auxiliar[pos_vacia++].posiciones[0] = i;
        }
}
    iniciales *letras = calloc((size_t) pos_vacia, sizeof(iniciales));
    if (pos_vacia == 0){                                                            //en caso de solo strings vacios
        return 0;
        }
    else if(pos_vacia  == n){                                                       //ninguna se repite
        return 0;
    }
    else {
        int contador = 0;
        for (i = 0; i < pos_vacia; i++) {
            if (auxiliar[i].repeticiones > 1) {                                     //agregar en caso de repetirse
                letras[i] = auxiliar[i];
                contador++;
            }
        }
        letras = realloc(letras, contador * sizeof(iniciales));
        free(auxiliar);
        if (letras == NULL){                                                        //si ninguna se repite
            return 0;
        }

    }
    int aux, max = 0;                                               //variables para almacenar el largo del prefijo
    for (i=0; i<pos_vacia; i++){                                    //iterar ssegun cantidad de iniciales asignadas
        int repes = letras[i].repeticiones;
        char *S2[repes];                                            //armar string para continuar recursivamente
        for (j=0; j<repes; j++){
            S2[j] = &S[letras[i].posiciones[j]][1];
        }
        aux = pCML(S2, repes) + 1;                                  //actualizar valor de prefijo de inicial actual
        if (aux > max){                                             // aux actual es mayor al maximo general
            max = aux;
        }
    }
    free(letras);
    return max;
}

int main() {
    char *prueba[20];
    prueba[0] = "holaaaaaaaaaaaaaaaaaaaaaaaa";
    prueba[1] = "holaaaaaaaaaaaaaaaaaaaaaaab";
    prueba[2] = "esternocleidomastoideo";
    prueba[3] = "esternon";
    prueba[4] = "abcdefghijklmnopqrstuvwxyz";
    prueba[5] = "estertor";
    prueba[6] = "ese";
    prueba[7] = "algo";
    prueba[8] = "algo";
    prueba[9] = "algo";
    prueba[10] = "alga";
    prueba[11] = "alga";
    prueba[12] = "alga";
    prueba[13] = "alguien";
    prueba[14] = "alguien";
    prueba[15] = "alguien";
    prueba[16] = "alguno";
    prueba[17] = "alguno";
    prueba[18] = "alguien";


    clock_t begin, end;
    double time_spent;
    begin = clock();

    int prefix = pCML(prueba, 19);

    end = clock();
    time_spent = (double) (end - begin) / CLOCKS_PER_SEC;

    printf("largo prefijo = %d\n, en un tiempo de %lf clock/s\n", prefix, time_spent);
}