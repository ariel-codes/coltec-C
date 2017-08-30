#include <stdio.h>
#include <math.h>
int main (void){
srand(time(NULL));
int gamesum = 0, play1=0, play2=0, play3=0, special, carta, sim=1;
printf("\n Bem vindo ao Vinte & Um \n Começando jogo pelo jogador UM de 3 "); // Introduz o jogo e em seguida gera e apresenta uma nova carta ao jogador até atingir o limite máximo
printf("Começando jogo pelo jogador UM de 3 \n");
while( gamesum <21 && sim!=0){
		printf("Mandar próxima carta? ( 0 pra parar ) \n");
		scanf("%d" , &sim);
		carta = rand() % 10;
		special= rand() % 3;
		switch(carta){
			case 1:
			printf("Vc tirou um Ás");
			break;
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:
			printf("Vc tirou um %d" , carta);
			break;
			case 10:
			if(special==0)
				printf("Vc tirou um Valete");
			if(special==1)
				printf("Vc tirou uma Dama");
			if(special==2)
				printf("Vc tirou um Rei");
			break;
			}
		gamesum = carta + gamesum;
		
	}
if (gamesum > 21)
	play1=1;
else if (gamesum == 21)
	play1=2;
gamesum=0;

srand(time(NULL));
printf("Agr é o jogador DOIS de 3 \n");
while( gamesum <21 && sim!=0){
		printf("Mandar próxima carta? ( 0 pra parar ) \n");
		scanf("%d" , &sim);
		carta = rand() % 10;
		special= rand() % 3;
		switch(carta){
			case 1:
			printf("Vc tirou um Ás");
			break;
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:
			printf("Vc tirou um %d" , carta);
			break;
			case 10:
			if(special==0)
				printf("Vc tirou um Valete");
			if(special==1)
				printf("Vc tirou uma Dama");
			if(special==2)
				printf("Vc tirou um Rei");
			break;
			}
		gamesum = carta + gamesum;
		
	}
if (gamesum > 21)
	play2=1;
else if (gamesum == 21)
	play2=2;
gamesum=0;

srand(time(NULL));
printf("Começando jogo pelo jogador DOIS de 3 \n");
while( gamesum <21 && sim!=0){
		printf("Mandar próxima carta? ( 0 pra parar ) \n");
		scanf("%d" , &sim);
		carta = rand() % 10;
		special= rand() % 3;
		switch(carta){
			case 1:
			printf("Vc tirou um Ás");
			break;
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:
			printf("Vc tirou um %d" , carta);
			break;
			case 10:
			if(special==0)
				printf("Vc tirou um Valete");
			if(special==1)
				printf("Vc tirou uma Dama");
			if(special==2)
				printf("Vc tirou um Rei");
			break;
			}
		gamesum = carta + gamesum;
		
	}
if (gamesum > 21)
	play3=1;
else if (gamesum == 21)
	play3=2;
gamesum=0;

printf("Fim de Jogo! Hora dos Resultados:");
switch(play1){
	case 1: printf("Jogador UM Perdeu");
	break;
	case 2: printf("Jogador UM Ganhou");
	}
switch(play3){
	case 1: printf("Jogador DOIS Perdeu");
	break;
	case 2: printf("Jogador DOIS Ganhou");
	}
switch(play3){
	case 1: printf("Jogador TRES Perdeu");
	break;
	case 2: printf("Jogador TRES Ganhou");
	}



}

