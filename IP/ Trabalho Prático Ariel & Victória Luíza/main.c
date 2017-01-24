#include "utilities.h"
#include "cliente.h"
#include "gerente.h"

#ifndef __unix__
#error Esse programa tem como foco sistemas linux e nao foi testado em outras plataformas!
#endif

/********************************************//**
 * Esse software é protegido pelas leis internacionais de proteção à propriedade intelectual e as leis de Deus
 *
 * Afinal de contas, só ele sabe como essa merda funciona
 * Não tocar/editar/olhar torto dessa linha pra baixo
 ***********************************************/

int main()
{
    //system("#/bin/bash \n chmod 7700 -R files");
    printf("\033[2J");
    printf("\033[0;0H"); // Setando o cursor do terminal na posição 0,0
    /**
    	Bloco de setup
    */
    //add_user();
    exit(42);
    bool logged=false;
    char run;
    user current;
    printf("\n ------------------------------------------------- \nBem vindo ao digital banking da YSolutions\n ------------------------------------------------- \n ");
    sleep(3);
    /**
    	Bloco de Login:
    */
    current=logger(logged);
    if(current.admin==true)
        {
            free_user(current);
            admin_menu();
        }
    else if(current.numero!=NULL)
        user_menu(current);
    /**
    	Bloco que realiza o loop do programa
    */
    printf("\n Deseja terminar? (S ou n): ");
    getchar();
    scanf("%c", &run);
    if(run=='N' || run=='n')
        main();
    else return 0;
}
//if(nota>60%); set ariel=happy;
