#ifndef SORTER_H_INCLUDED
#define SORTER_H_INCLUDED
#include <stdlib.h>

void quickSort(int valor[], int esquerda, int direita);

void bubbleSort(int vetor[], int tamanho);

/**< Shell sort é o mais eficiente algoritmo de classificação dentre os de complexidade quadrática. */
void shellSort(int *vet, int vect_size);

void cocktailSort(int list[10], int bottom, int top );

void insertionSort(int numeros[], int tam);

#endif // SORTER_H_INCLUDED
