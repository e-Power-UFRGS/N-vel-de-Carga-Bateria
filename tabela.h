#include <stdio.h>

void tabela(float *tensao, int *capacidade);
/*
Print tabela com 100 valores de tens�o diferentes e sua porcentagem equivalente
tensao = vetor com os valores de tens�o
capacidade = vetor com a porcentagem (de 0 a 100)
*/
int porcentagem(float valor, float *tensao, int *capacidade);
/*
Recebe um valor de tensao e retorna a porcentagem equivalente mais pr�xima
valor = valor da tens�o que deseja
tensao = vetor com os valores de tens�o
capacidade = vetor com a porcentagem (de 0 a 100)
*/
