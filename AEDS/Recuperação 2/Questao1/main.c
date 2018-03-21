#include <stdio.h>
#include "listas.h"

lista* game;

void setup(int n){
	lista* last;
	game=lst_insere(game, n);
	last=game;
	printf("\nInserindo #%d: %p\n", n, last);
	n--;
    for(n-1; n>0; n--){
		printf("Inserindo #%d: ", n);
        game=lst_insere(game, n);
        printf("%p \n", game);
    }
	last->prox=game;
}

void perdeu(lista* last){
    lista* loser=game;
    last->prox=game->prox;
    game=game->prox;
    free(loser);
}

int roda_roda(int m, int n){
	int i=n+1;
	setup(n);
	lista* last=game->prox;
	while(game->prox!=game){
        for(i=1; i<=m; i++){
			last=game;
            game=game->prox;
        }
        printf("\nRetirando jogador %d #%p", game->info, game);
		perdeu(last);
	}
	return game->info;
}

int main(){
    int m,n;
    printf("Insira o número de pessoas e de passes:");
    scanf("%d %d", &n, &m);
	printf("\n\tO jogador vencedor é: %d", roda_roda(m, n));
	free(game);
	return 0;
}
