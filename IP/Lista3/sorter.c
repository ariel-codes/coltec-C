#include <stdlib.h>
#include "sorter.h"

void quickSort(int valor[], int esquerda, int direita)
{
    int i, j, x, y;
    i = esquerda;
    j = direita;
    x = valor[(esquerda + direita) / 2];

    while(i <= j)
    {
        while(valor[i] < x && i < direita)
        {
            i++;
        }
        while(valor[j] > x && j > esquerda)
        {
            j--;
        }
        if(i <= j)
        {
            y = valor[i];
            valor[i] = valor[j];
            valor[j] = y;
            i++;
            j--;
        }
    }
    if(j > esquerda)
    {
        quickSort(valor, esquerda, j);
    }
    if(i < direita)
    {
        quickSort(valor,  i, direita);
    }
}

void bubbleSort(int vetor[], int tamanho)
{
    int aux=0, i=0, j;
    for(i=tamanho-1; i >= 1; i--)
    {
        for(j=0; j < i ; j++)
        {
            if(vetor[j]>vetor[j+1])
            {
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
    }
}

/**< Shell sort é o mais eficiente algoritmo de classificação dentre os de complexidade quadrática. */
void shellSort(int *vet, int vect_size)
{
    int i , j , value;
    int gap = 1;
    while(gap < vect_size)
    {
        gap = 3*gap+1;
    }
    while ( gap > 1)
    {
        gap /= 3;
        for(i = gap; i < vect_size; i++)
        {
            value = vet[i];
            j = i - gap;
            while (j >= 0 && value < vet[j])
            {
                vet [j + gap] = vet[j];
                j -= gap;
            }
            vet [j + gap] = value;
        }
    }
}

void cocktailSort(int list[10], int bottom, int top )
{
    int swapped=0,i=0,aux=0;
    while(swapped == 0 && bottom < top)
    {
        swapped = 1;
        for(i = bottom; i < top; i++)
        {
            if(list[i] > list[i + 1])
            {
                aux=list[i];
                list[i]=list[i+1];
                list[i+1]=aux;
                swapped = 0;
            }
        }
        top = top - 1;
        for(i = top; i > bottom; i--)
        {
            if(list[i] < list[i - 1])
            {
                aux=list[i];
                list[i]=list[i-1];
                list[i-1]=aux;
                swapped = 0;
            }
        }
        bottom = bottom + 1;
    }
}

void insertionSort(int numeros[], int tam)
{
    int i, j, eleito;
    for (i = 1; i < tam; i++)
    {
        eleito = numeros[i];
        j = i - 1;
        while ((j>=0) && (eleito < numeros[j]))
        {
            numeros[j+1] = numeros[j];
            j--;
        }
        numeros[j+1] = eleito;
    }
}
