#include <stdio.h>
#include <stdlib.h>

void add(int a[3][3], int b[3][3]);
void multiply(int a[3][3], int b[3][3]);

int main()
{
	void (*ops[2])(int[3][3], int[3][3])={add, multiply};
	int escolha;
	int b[3][3]={1,2,3,4,5,6,7,8,9};
	int a[3][3]={1,2,3,4,5,6,7,8,9};

    printf("A complexidade é Multiply=O(n³) & Add=O(n²), onde n corresponde ao tamanho da matriz quadrada ;) \nEscolha: 0 para somar, 1 para multiplicar\n");
    scanf("%d", &escolha);
    switch(escolha){
		case 0:
			(ops[0])(a, b);
			break;
		case 1:
			(ops[1])(a, b);
    }
    return 0;
}

void add(int a[3][3], int b[3][3]){
	int i, l;
	for(i=0; i<3; i++){
		printf("\n");
		for(l=0; l<3; l++){
            printf("\t%d", (a[i][l]+b[i][l]));
		}
	}
}

void multiply(int a[3][3], int b[3][3]){
	int i, l, m, n, temp=0;
	for(i=0; i<3; i++){
		printf("\n");
		for(l=0; l<3; l++){
            for(m=0; m<3; m++){
                temp=temp+a[l][m]*b[m][l];
			}
			printf("\t%d", temp);
			temp=0;
		}
	}
}
