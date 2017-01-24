#include <stdio.h>
#include <stdlib.h>

int ackr(m, n){
	if(m==0)
		return n+1;
	else if(m>0 && n==0)
		ackr(m-1, 1);
	else ackr(m-1, ackr(m, n-1));
}

float vet(float* vect, int tamanho,  int sum, int pos, int cont){
	if(vect[pos]<0)
		cont--;
	else sum=vect[pos]+sum;
	if(pos==tamanho-1){
		printf("%d \t %d", sum, pos);
		sum=sum/cont;
		return sum;
	}
	else return vet(vect, tamanho, sum, pos+1, cont);
}

int main(){
	char opt;
	float avrg;
	int m, n, tam;
	float* vect;
	printf("Escolha a letra: ");
	scanf("%c" ,&opt);
	switch(opt){
	case 'a':
		printf("Entre seus dois argumentos para A(m, n)");
		scanf("%d %d" , &m, &n);
		printf("\n \t %d \n" , ackr(m, n));
		break;
	case 'b':
		printf("Insira o tamanho do vetor:");
		scanf("%d", &tam);
		vect=(float*) malloc(tam*sizeof(float));
		for(m=0; m<tam; m++){
			printf("Vetor[ %d ]" , m);
			scanf("%f" , &vect[m]);
		}
		avrg=0;
		avrg=vet(vect, tam, 0, 0, tam);
		printf("\n %f \n" , vet(vect, tam, 0, 0, tam));
		break;
	default:
		printf("Opcao inválida");
	}
	return 0;
}
