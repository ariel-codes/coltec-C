#include <stdio.h>
#include <stdlib.h>
//#include "pilha.h"
//#include "listas.h"

typedef struct testes
{
    int* carta;
    int n;
    int cartas;
    int players;
} teste;

typedef struct lista_de_testes
{
    teste data;
    struct lista_de_testes* prev;
} lista_testes;

typedef struct pilha_testes
{
    lista_testes* top;
} p_testes;

typedef struct lst_jogador
{
    char id;
    struct lst_jogador* prox;
} jogador;

typedef struct lst_carta
{
    int val;
    struct lst_carta* prev;
} carta;

typedef struct p_monte_jogador
{
    carta* top;
} monte_jog;

void push(p_testes* pile, teste v)/// INSERE MAIS UM CASO DE TESTE A SER EXECUTADO
{
    lista_testes* novo= (lista_testes*) malloc(sizeof(lista_testes));
    novo->prev=pile->top;
    novo->data=v;
    pile->top=novo;
}

void push_carta(monte_jog* pile, int val)///INSERE MAIS UMA CARTA NO TOPO DA PILHA
{
    carta* novo= (carta*) malloc(sizeof(carta));
    novo->val=val;
    novo->prev=pile->top;
    pile->top=novo;
}

void insere_teste(teste caso, FILE* entrada) ///LÊ O CASO DE TESTE POR INTEIRO E SETA AS VARIÁVEIS
{
    printf("\n Lendo o caso de teste #%d", caso.n);
    int cont, carta_num;
    caso.carta=(int*) malloc(sizeof(int)*caso.cartas);
    for(cont=caso.cartas; cont>0; cont--)
        {
            fscanf(entrada, "%d", &carta_num);
            caso.carta[cont]=carta_num;
        }
}

jogador* lst_insere(jogador *l, int i)  ///INSERE UM JOGADOR NA LISTA DE JOGADORES
{
    jogador* item= malloc(sizeof(jogador));
    item->prox= l;
    item->id= i;
    return item;
}

jogador* playsetter(int num)  ///CRIA A LISTA CIRCULAR DE JOGADORES
{
    printf("\n Criando a lista circular de jogadores...");
    int i;
    jogador* player_lst= (jogador*) malloc(sizeof(jogador));
    player_lst->id=num;
    jogador* last=player_lst;
    for(i=num-1; i>0; i--)
        {
            player_lst=lst_insere(player_lst, i);
        }
    last->prox=player_lst;
    return player_lst;
}

monte_jog* def_compra(int carta[], int cartas) 	///CRIA A PILHA DE CARTAS
{
    int i;
    monte_jog* pile=(monte_jog*) malloc(sizeof(monte_jog));
    pile->top=NULL;
    for(i=1; i<=cartas; i++)
        {
            push_carta(pile, carta[i]);
        }
}

void game(FILE* output, monte_jog* compra, monte_jog* pl_jog, jogador* jogadores, p_testes* pile)  ///FAZ OS CÁLCULOS DO JOGO EM SI E DETERMINA O VENCEDOR
{
    while(compra->top!= NULL)
        {

        }
}

FILE* executor(p_testes* pile) ///EXECUTA AS TAREFAS FINAIS E OS CASOS DE TESTE SEQUENCIALMENTE
{
    jogador* lst_jog;
    monte_jog* pl_jog;
    monte_jog* pl_compra;
    monte_jog* swap;
    FILE* saida;
    saida=fopen("saida.txt", "w");

    while(pile->top!=NULL)
        {
            lst_jog=playsetter(pile->top->data.players);
            pl_compra=def_compra(pile->top->data.carta, pile->top->data.cartas);
            pl_jog=(monte_jog*) malloc(sizeof(monte_jog)*pile->top->data.players);
            game(saida, pl_compra, pl_jog, lst_jog, pile);

            swap=pile->top;
            pile->top=pile->top->prev;
            free(swap);
        }
}

int main()
{
    FILE* testes;
    int count=0;
    testes=fopen("entrada.txt", "r");
    ftell(testes);
    teste atual;

    p_testes* pile= (p_testes*) malloc(sizeof(p_testes));
    pile->top= NULL;

    while(1)
        {
            count++;
            fscanf(testes, "%i %i", &atual.cartas, &atual.players);
            if((atual.cartas==0 && atual.players==0) || atual.cartas<atual.players || atual.players<2 || atual.players>20 || atual.cartas>10000 || atual.cartas<2)
                {
                    printf("\n Arquivo terminado ou com erro, saindo do modo de leitura");
                    break;
                }
            atual.n=count;
            insere_teste(atual, testes);
            push(pile, atual);
        }
    executor(pile);
    return 0;
}
