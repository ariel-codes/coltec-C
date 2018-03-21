#include "utilities.h"
#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

///Funções auto-explicativas, suponho
/// Em algumas fui forçado a usar scripts em bash, já q as funçoes de arquivo para C são ""imprevisíveis"" aka bugentas

void user_menu(user current);

void extrato(user current);

void transfer(user current);

void saque(user current);

void deposito(user current);

void lister();

#endif // CLIENTE_H_INCLUDED
