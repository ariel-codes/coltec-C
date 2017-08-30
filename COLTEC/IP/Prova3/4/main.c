#include <stdio.h>
#include <stdbool.h>
#include <stdio.h>
#include "matrix.h"

bool um(int** matriz, int linhas, int colunas){
	int count, i, j;
	int** t;
	int** neg;
	count=linhas*colunas;
	t=cria2d(linhas, colunas);
	neg=cria2d(linhas, colunas);
	for(i=0; i<linhas; i++){
		for(j=0; j<colunas; j++){
			t[i][j]=matriz[j][i];
			neg[i][j]=matriz[i][j] - matriz[i][j] - matriz[i][j];
		}
	}
	for(i=0; i<linhas; i++){
		for(j=0; j<colunas; j++){
			if(t[i][j]==neg[i][j])
				count--;
		}
	}
	if(count==0)
		return true;
	else return false;
}

void printa_matriz(int** matriz, int linhas, int coluna){
	int i=0, j=0;
	while(i<linhas && j<coluna){
		printf("%d \t" , matriz[i][j]);
		if(j==coluna-1){
			printf("\n");
			j=0;
			i++;
		} else j++;
	}
}

void dois(int** matriz,  int linha, int coluna){
	int i, j;
	for(i=0; i<linha; i++){
		for(j=0; j<coluna; j++){
			if(i==j)
				matriz[i][j]=1;
			else matriz[i][j]=0;
		}
	}
	i=0;
	j=coluna-1;
	while(i<linha && j>=0){
		matriz[i][j]=1;
		j--;
		i++;
	}
	printa_matriz(matriz, linha, coluna);
}

void encher_matriz(int** matriz, int linhas, int colunas){
	int i, j;
	for(i=0; i<linhas; i++){
		for(j=0; j<colunas; j++){
			printf("Coluna %d, linha %d :" , i , j);
			scanf("%d" , &matriz[i][j]);
		}
	}
}

int main(){
	char opt;
	int tam1, tam2;
	int** matriz1;
	printf("Escolha a letra: ");
	scanf("%c" ,&opt);
	switch(opt){
	case 'a':
		printf("\n Insira o tamanho da sua matriz (n por n): ");
		scanf("%d %d", &tam1, &tam2);
		matriz1=cria2d(tam1, tam2);
		encher_matriz(matriz1, tam1, tam2);
		printf("Anti-simetrica: %d" , um(matriz1, tam1, tam2));
		break;
	case 'b':
		printf("\n Insira o tamanho da sua matriz (n por n): ");
		scanf("%d %d", &tam1, &tam2);
		matriz1=cria2d(tam1, tam2);
		dois(matriz1, tam1, tam2);
		break;
	default:
		printf("Opcao inválida");
	}
	return 0;
}
