#include <stdio.h>
#include "tabela.h"

int porcentagem(float valor, float *tensao, int *capacidade){
    float dif_maior, dif_menor;

    if (valor >= 4.1){
        return 100;
    }
    else if (valor <= 2.5){
        return 0;
    }

    for (int i = 100; i>=0; i--){
        if (tensao[i] > valor){
            dif_maior = tensao[i] - valor;
            dif_menor = valor - tensao[i+1];

            if (dif_maior < dif_menor){
                 return 100 - capacidade[i];
            }

            else if (dif_menor < dif_maior){
                return 100 - capacidade[i+1];
            }

            else{
                return 100 - capacidade[i];
            }
        }
    }
}

void tabela(float *tensao, int *capacidade){

    printf("TENSAO     CAPACIDADE\n");

    for (int i = 100; i>=0; i--){
        printf("%.3f  ->     %d%%\n", tensao[i], 100 - capacidade[i]);
    }
}
