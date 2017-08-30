#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <crypt.h>
#include <termios.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>

#ifndef UTILITIES_H_INCLUDED
#define UTILITIES_H_INCLUDED
#include <stdbool.h>

typedef struct _user
{
    char* numero;///Tamanho padrão=10
    char* senha;///Tamanho padrão=8
    bool admin;
    float saldo;
    float limite;
    char* data; ///Tamanho padrão=18
    char* nome; ///Tamanho padrão=50
} user;

static const char user_list[] = "./files/login";
static const char user_unique[] = "./files/contas/";
static const char reservas[] = "./files/reserve" ;

user free_user(user aloc); /// Escreve o log das operações do cliente no /files/contas/*.log

//void refresh(); Função obsoleta

void acresce_char(char* number, int pos); ///Aumenta a string de números user.numero em 1, para poder imprimir ao arquivo de login

void log_user(char op, char* origem , float value, char* destino);

void write_user(user usr, bool is_new); ///Escreve nos arquivos /files/login e /files/contas/*.acc

user aloc_user(); ///Faz a alocação das strings na struct user, usando os tamanhos padroes

user logger(bool logged);
/// Realiza o login dos usuários, utiliza o algoritmo de enciptação one-way MD5, gerando um hash a partir da senha inputada pelo usuário
///e usando o número da conta como salt. A senha real do usuário nao é armazenada, e no login o hash gerado pelo input do usuário é comparado
///com o hash associado ao número no arquivo de login

void read_user(char number[10], user account); ///Lê o arquivo /files/contas/*.acc e preenche a struct user

char* get_time(); /// Cria uma string com a data e horário atual (em GMT), no formato DD/MM/AAAA-HH:MM:SS

void fgets_n(char* str1, int num); /// Simplesmente uma fgets que retira o \n no final da string

char* loadfile_str(char* input_file_name); /// Carrega todo um arquivo de texto em uma string

void add_money(float money); /// Simplesmente adiciona ou retira dinheiro da reserva do banco, como em saques, depósitos e adição de clientes

#endif //UTILITIES_H_INCLUDED
