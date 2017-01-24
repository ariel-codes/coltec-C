# include <stdio.h>
# include <math.h>
# include <string.h>

// Parâmetros de alocação de memória (MALLOC=MORTE)
	int Size_m=500;
	void * Free_m;

int um (int A ,int B,int C){
	C = (A*360)+(B*30)+ C ;
	return (C);
}
char dois (int A){
	char nota;
	if(A>=0 && A<=49)
		nota = 'D';
	if(A>=50 && A<=69)
		nota = 'C';
	if(A>=70 && A<=89)
		nota = 'B';
	if(A>= 90 && A<=100)
		nota = 'A';
	return (nota);
}
float tres (float AF){
	return ((4*3.14*pow( AF, 3))/3);
}
int quatro (int A, int B){
	int impar = 0;
	if (B % 2 !=0)
		impar++;
	while(A != B){
		if ( A % 2 !=0)
			impar ++;
		if (A < B)
			A++;
		if (A > B)
			A--;
	}
	return (impar);
}

char * cinco (int B,int C){
	Free_m= malloc(Size_m);
	char *p = Free_m; // Parece desnecessário porém preciso deste nível de separação de Free_m
	char str1[10];
	p=str1;
	int a = ((B-1)*30)+ C;
	if (a < 80 || a >= 355)
		strcpy(str1, "Verao");
	if (a >= 80 && a < 172)
		strcpy(str1, "Outono");
	if (a >= 172 && a < 265)
		strcpy(str1, "Inverno");
	if (a >= 265 && a < 355)
		strcpy(str1, "Primavera");
	return p;
}

int seis(int A ,int B){
    int result;
    result=A/B;
    printf("Resultado: %d" , result);
    return (A%B);
}

int sete(int A,int B){
    int soma;
    soma=A;
    while(A!=B){
        if(A<B){
            soma=soma+(A+1);
            A++;
        }
        if(A>B){
            soma=soma+(B+1);
            A--;
        }
    }
    return soma;
}


float oito (float A){
    float result=0;
    while(A!=0){
        result= result+(1/A);
        A--;
    }
    return result;
}
short nove(){
    short cont=10, neg;
    int num[cont];
    for(cont=1; cont<=10; cont++){
        scanf("%d" , &num[cont]);
        if(num[cont]<0)
            neg++;
    }
    return neg;
}

int dez(){
    short cont;
    int vect[10], maior=0;
    printf("Digite 10 números");
    for(cont=0; cont<10; cont++){
        scanf("%d", &vect[cont]);
        if(vect[cont]>maior)
            maior=vect[cont];
    }
    return maior;
}

int onze(){
    short cont;
    int vect[10], maior=0;
    printf("Digite 10 números");
    for(cont=0; cont<10; cont++){
        scanf("%d", &vect[cont]);
        if(vect[cont]<maior)
            maior=vect[cont];
    }
    return maior;
}

void doze(){
	int vt[10], cont, swap, cont2;
	for(cont=0; cont<10; cont++){
        scanf("%d", &vt[cont]);
	}
	for(cont=0; cont<10; cont++){
        for(cont2=0; cont2<10; cont2++){
            if(vt[cont]>vt[cont2]){
                swap=vt[cont];
                vt[cont]=vt[cont2];
                vt[cont2]=swap;
            }
        }
	}
    for(cont=0; cont<10; cont++){
        printf("R: %d \n", vt[cont]);
	}
}

int treze(){
    int vt[10], cont, sum=0;
    for(cont=0; cont<10; cont++){
        scanf("%d", &vt[cont]);
        sum=vt[cont]+sum;
	}
	return sum;
}

int main(){
	int opt, A, B, C;
	float AF;
	char S[50];
	printf("Ohhh lista cansativa, escolhe o exercícío aí \n");
	scanf("%d" , &opt);
	while ( opt != 0){
		switch (opt){
			case 1:
				printf("Diga sua idade em anos, meses e dias:");
				scanf("%d %d %d" , &A , &B, &C );
				printf("Você tem %d dias de vida" , um(A, B, C));
				break;
			case 2:
				printf("Diga sua média:");
				scanf("%d" ,&A);
				printf("%c" , dois(A));
				break;
			case 3:
				printf("Insira o raio da esfera: ");
				scanf("%f" , &AF);
				printf("%f" , tres(AF));
				break;
			case 4:
				printf("Insira seus dois numeros:");
				scanf("%d %d", &A, &B);
				printf("%d", quatro(A, B));
				break;
			case 5:
				printf("Escreva o dia e o mês:");
				scanf("%d %d", &C, &B);
				printf("%s" ,cinco(B, C));
				free(Free_m);
				break;
            case 6:
                printf("Insira dois números para dividir:");
                scanf("%d %d" ,&A ,&B);
                printf("\n (O resto é %d)" , seis(A, B));
                break;
            case 7:
                printf("Insira o intervalo a ser somado:");
                scanf("%d %d" ,&A ,&B);
                printf("\n Resultado: %d" , sete(A, B) );
                break;
            case 8:
                printf("Insira um valor inteiro:");
                scanf("%d" , &A);
                printf("%f" , oito(A));
                break;

            /**< Parte II - Vetores */
            case 9:
                printf("%hd desses valores são negativos" ,nove());
                break;
            case 10:
                printf("%d é o maior valor" , dez());
                break;
            case 11:
                printf("%d é o maior valor" , onze());
                break;
            case 12:
                doze();
                break;
            case 13:
                printf("%d" ,treze());
                break;
            case 20:
                printf("Insira sua string:");
                gets( S );
        }
		printf("\n ________________________________________________________________ \n \n  Escolha outro , ou use '0' para sair \n");
		scanf("%d" , &opt);
	}
	return 0;
}
