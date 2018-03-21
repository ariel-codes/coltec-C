#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main (void)
{
	int linha, coluna;
    int **matr;
    int ***matr3d;
	printf("Insira o tamanho de sua matriz (linhas , colunas)");
	scanf("%d %d" , &linha, &coluna);
	matr=cria2d(linha, coluna);
	limpa2d(matr, linha, coluna);
	matr3d=cria3d(5, 5, 5);
	limpa3d(matr3d, 5, 5, 5);
	return 0;
}
