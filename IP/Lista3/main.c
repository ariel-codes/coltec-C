#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include <stdbool.h>
#include <math.h>
#include "sorter.h"

long int um(int** matriz)
{
    fill2d(matriz, 5, 5);
    long int soma=0;
    short i, j;
    for(i=0; i<5; i++)
    {
        for(j=0; j<5; j++)
            soma+=matriz[i][j];
    }
    return soma;
}

long int dois(int** matriz)
{
    fill2d(matriz, 6, 6);
    short i=0, j=0;
    long int soma=0;
    while(i<6 && j<6)
    {
        soma+=matriz[i][j];
        j++;
        i++;
    }
    j=-1;
    while(i>0 && j<6)
    {
        j++;
        i--;
        soma+=matriz[i][j];
    }
    return soma;
}

long int tres(int** matriz)
{
    long int soma;
    short i;
    fill2d(matriz, 7, 6);
    for(i=0; i>6; i++)
        soma+=matriz[5][i];
    for(i=0; i>7; i++)
        soma+=matriz[i][3];
    return soma;
}

long int quatro()
{
    return -1;
}

int main()
{
    short opt=21;
    while(opt!=0)
    {
        printf("\n \a Lista de Exercicios #3 \n Escolha o exercicio:") ;
        scanf("%hi" , &opt);
        switch(opt)
        {
        case 1:
            printf("%li \n", um(cria2d(5, 5)) );
            break;
        case 2:
            printf("%li \n", dois(cria2d(6, 6)) );
            break;
        case 3:
            printf("%li \n", tres(cria2d(7, 6)) );
            break;
        case 4:
            printf("%li \n", quatro(cria2d(6,6)) );
            break;
        case 5:
            break;
        case 21:
            //debugmatrix();
            break;
        case 0:
            break;
        default:
            printf("Esse exercicio nao existe, tente outro ou 0 para sair \n");
        }
        fflush(stdin);
    }
    return 0;
}
