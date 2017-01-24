#include "gerente.h"

void add_user()
{
    fflush(NULL);
    FILE* file;
    user new_;
    char admin;
    char numero[10];
    char confirm;
    int i=0;
    file=fopen(user_list, "r");
    if(file==NULL)
    {
        perror("\n \t File Error!!!");
        exit(-1000);
    }
    else
    {
        fflush(file);
        fseek(file, -10, SEEK_END); /// Volta o pointer pra posição do último número de conta
        fgets(numero, 10, file);
        while(numero[i]!='\n' && i<10)
        {
            i++;
        }
        numero[i]='\0';
        printf("\n O número da nova conta será %s \n", numero);
        new_=aloc_user(new_);
        strcpy(new_.numero, numero);
        fflush(stdin);
        strcpy(new_.senha, crypt(getpass("Entre a senha: (máximo de 8 caracteres):"), numero));
        fflush(NULL);
        printf("Entre o nome completo do usuario:");
        fgets_n(new_.nome, 50);
        printf("\n Essa conta é para um gerente? (s ou N): ");
        fflush(stdin);
        scanf("%c" , &admin);
        if(admin=='s' || admin=='S')
            {
                new_.admin=true;
                new_.limite=0;
                new_.saldo=0;
            }
        else{
            new_.admin=false;
            printf("\n Entre o limite da conta:");
            fflush(stdin);
            scanf("%f" , &new_.limite);
            printf("\n Insira o saldo inicial da conta n. %s: ", numero);
            fflush(stdin);
            scanf("%f" , &new_.saldo);
        }
        new_.data=get_time();
        printf("\n Revisão: \n \t Numero: %s \n \t Nome: %s \n \t Gerente: %d \n \t Limite: %.2f \n \t Saldo inicial: %.2f \n \t Data de Criação: %s \n", new_.numero, new_.nome, new_.admin, new_.limite, new_.saldo, new_.data);
        fflush(stdin);
        printf("\nConfirmar criação? (s ou N): ");
        fflush(stdin);
        getchar();
        scanf("%c" , &confirm);
        if(confirm=='s' || confirm=='S')
            {
                if(new_.admin==false)
                    add_money(new_.saldo);
                write_user(new_, true);
            }
        else printf("Operação cancelada");
        free_user(new_);
        system("./files/script.sh");
    }
    fflush(NULL);
}

void rm_user()
{
    printf("\033[2J");
    printf("\033[0;0H");
    system("#bin/bash \n touch temp \n echo (Lembre-se que TODAS as contas tem, necessariamente, 9 dígitos) \n sleep 2 \n echo Insira o número da conta a ser removida: \n read conta1 \n echo Confirme o número da conta: \n read conta \n if [ $conta1 = $conta ] ; then \n rm ./files/contas/$conta.acc \n rm ./files/contas/$conta.log \n grep -v \"$conta\" ./files/login > temp \n mv temp ./files/login \n sleep 3 \n else \n echo Contas Inconsistentes! \n fi");
}

void set_limite()
{
    char* numero;
    user account;
    account=aloc_user(account);
    printf("\033[2J");
    printf("\033[0;0H");
    printf("\n Insira o numero da conta a ter o limite alterado: ");
    numero= (char*) calloc(10, sizeof(char));
    fgets_n(numero, 10);
    read_user(numero, account);
    printf("\n Insira o novo limite:");
    scanf("%f", &account.limite);
    write_user(account, false);

    free_user(account);
    free(numero);
}

void lister(){
    system("#/bin/bash \n cd files/contas/ \n ls *.acc \n");
    printf("\nAPERTE ENTER PARA CONTINUAR \n");
    getchar();
}

void reserva(){
    system("#/bin/bash \n cd files \n cat reserve");
    printf("\nAPERTE ENTER PARA CONTINUAR \n");
    getchar();
}

void admin_menu()
{
    short opt;
    do
    {
        printf("\n -Login Efetuado com Sucesso-");
        printf("\033[2J");
        printf("\033[0;0H");
        printf("Escolha a operação a ser realizada: \n \t 1) Adicionar conta \n \t 2) Remover conta \n \t 3) Alterar limite \n \t 4) Listar Clientes \n \t 5) Exibir reservas do banco \n \t 0) Sair \n \t");
        scanf("%hi", &opt);
        switch (opt)
        {
        case 1:
            add_user();
            break;
        case 2:
            rm_user();
            break;
        case 3:
            set_limite();
            break;
        case 4:
            lister();
            break;
        case 5:
            reserva();
        }
    }
    while(opt!=0);
    printf("\n\nFinalizando Acesso...");
    sleep(3);
    printf("\033[2J");
    printf("\033[0;0H");
}
