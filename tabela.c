#include <stdio.h>

int porcentagem(float valor, float *tensao, int *capacidade){
    int i, por, entrou = 0;
    float dif_maior, dif_menor;

    for (i = 100; i>=0; i--){
        if (valor >= 4.1){
            por = 100;
        }
        else if (valor <= 2.5){
            por = 0;
        }
        else if (tensao[i] > valor && entrou == 0){
            entrou = 1;
            dif_maior = tensao[i] - valor;
            dif_menor = valor - tensao[i+1];

            if (dif_maior < dif_menor){
                por = 100 - capacidade[i];
            }

            else if (dif_menor < dif_maior){
                por = 100 - capacidade[i+1];
            }

            else if (dif_menor == dif_maior){
                por = 100 - capacidade[i];
            }
        }
    }
    return por;
}

int main(){

    float tensao[101] = {4.1, 4.088, 4.064, 4.044, 4.032, 4.024, 4.012, 4.004, 4.004, 3.992, 3.988, 3.98, 3.972, 3.964,
    3.956, 3.94, 3.932, 3.92, 3.904, 3.892, 3.876, 3.868, 3.856, 3.844, 3.832, 3.824, 3.812, 3.804, 3.792,
    3.788, 3.776, 3.768, 3.76, 3.748, 3.74, 3.736, 3.724, 3.712, 3.7, 3.692, 3.684, 3.672, 3.66, 3.652, 3.64,
    3.632, 3.624, 3.616, 3.608, 3.6, 3.592, 3.584, 3.576, 3.568, 3.56, 3.556, 3.548, 3.54, 3.536, 3.528, 3.524,
    3.516, 3.508, 3.508, 3.5, 3.488, 3.48, 3.48, 3.476, 3.468, 3.46, 3.452, 3.444, 3.44, 3.428, 3.42, 3.412, 3.404,
    3.396, 3.384, 3.376, 3.368, 3.36, 3.348, 3.332, 3.316, 3.296, 3.276, 3.252, 3.216, 3.172, 3.12, 3.064, 3.004,
    2.944, 2.86, 2.656, 2.617, 2.578, 2.539, 2.5};

    int capacidade[101] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26,
    27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53,
    54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80,
    81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100};

    printf("TENSAO     CAPACIDADE\n");

    for (int i = 100; i>=0; i--){
        printf("%.3f  ->     %d%%\n", tensao[i], 100 - capacidade[i]);
    }

    int por;
    float valor;

    printf("\nDigite um valor: ");
    scanf("%f", &valor);

    por = porcentagem(valor, tensao, capacidade);

    printf("A tensao %.3f equivale a %d%%\n ",valor, por);
    return 0;
}
