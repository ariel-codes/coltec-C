#include <stdio.h>
#include <stdlib.h>

typedef struct exec_fila
{
    int id;
    int waiting;
    struct exec_fila* prox;
} thread;

typedef struct fila_exe
{
    thread* prim;
    thread* ult;
} fila_exec;

fila_exec* timeshare=NULL;

void clear (void)
{
    fflush(stdout);
    fflush(stdin);
}

void incluir()
{
  thread* novo= (thread*) malloc(sizeof(thread));
  printf("Insira o ID e o tempo máximo do processo: ");
  clear();
  scanf("%d %d", &novo->id, &novo->waiting);
  if(timeshare->prim== NULL && timeshare->ult== NULL)
    timeshare->prim=timeshare->ult=novo;
    else{
      thread* temp=timeshare->prim;
      thread* prev=temp;
      while(novo->waiting < temp->waiting)
      {
        prev=temp;
        temp=temp->prox;
      }
      if(timeshare->prim->waiting < novo->waiting)
      {
        novo->prox=temp;
        timeshare->prim=novo;
      }
      else
      {
        novo->prox=temp;
        prev->prox=novo;
      }
    }
}

int existe(int id)
{
    thread* swap=timeshare->prim;
    while(swap!=NULL)
    {
        if(swap->id==id)
            return 1;
        swap=swap->prox;
    }
    return 0;
}

void retirar()
{
  thread* out=timeshare->prim;
  timeshare->prim=timeshare->prim->prox;
  free(out);
}

void imprime()
{
    thread* print=timeshare->prim;
    while(print!=NULL)
    {
        printf("-->PROCESS (%d):%d\n", print->waiting, print->id);
        print=print->prox;
    }
}

int main()
{
    timeshare=(fila_exec*) malloc(sizeof(fila_exec));
    timeshare->prim=timeshare->ult=NULL;
    int op=4;
    while(op)
    {
        printf("O quê você quer fazer?\n\t 1 -> Incluir \n\t 2 -> Retirar \n\t 3 -> Listar \n\t 0 -> Sair \n");
        clear();
        scanf("%d", &op);
        clear();
        switch(op)
        {
        case 0:
            break;
        case 1:
            incluir();
            break;
        case 2:
            retirar();
            break;
        case 3:
            imprime();
        }
    }
    thread* swap;
    while(timeshare->prim!=NULL)
    {
        swap=timeshare->prim;
        timeshare->prim=timeshare->prim->prox;
        free(swap);
    }
    free(timeshare);
    return 0;
}
