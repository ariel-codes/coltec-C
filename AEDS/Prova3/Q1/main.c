#include <stdio.h>
#include <stdlib.h>


typedef struct pessoa{
	int codigo, idade;
	char nome[100];
} tripulante;

typedef struct hashtable{

} table;

int hash (int id){
    return 21-(id/2);
}

int main()
{
	FILE* man=fopen("aviao.txt", "r");
	if (man==NULL)
		exit(-5);
	int i[21];
	char nome[100];
	printf("Insira o nome do tripulante:");
	fscanf("%s", nome);
    return 0;
}
