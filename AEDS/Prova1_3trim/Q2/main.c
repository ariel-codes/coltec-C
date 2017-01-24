#include <stdio.h>
#include <stdlib.h>
typedef struct arv {

	int info ;
	struct arv *esq ;
	struct arv *dir ;
} tree ; //Árvore simples, quick'n'dirty

typedef struct arv_stat {
   tree* arv;
   tree* son;
   int pos;
} status;

status deepmost(tree* arv){
   tree* left=arv->esq;
   tree* right=arv->dir;
   tree* parent=arv;
   status child;
   int alt_L, alt_R;
   for(alt_L=0; left!=NULL; alt_L--){
      parent=left;
      left=left->dir;
   }
   for(alt_R=0; right!=NULL; alt_R++){
      parent=right;
      right=right->esq;
   }
   if((0-alt_L)>alt_R){
      child.son=left;
      child.arv=parent;
      child.pos=alt_L;
      return child;
   }
   else {
      child.son=right;
      child.arv=parent;
      child.pos=alt_R;
      return child;
   }
}

void remover(tree* arv, tree* parent) {
   int orig;
   if(parent->esq==arv)
      orig=-1;
   else if(parent->dir==arv)
      orig=1;
   else return;
   if(arv->esq==NULL && arv->dir==NULL){
    if(orig==1)
        parent->dir=arv->esq;
    else parent->esq=arv->esq;
   }
   else if(arv->esq!=NULL && arv->dir==NULL){
      if(orig==1)
         parent->dir=arv->esq;
      else parent->esq=arv->esq;
   }
   else if(arv->esq==NULL && arv->dir!=NULL){
      if(orig==1)
         parent->dir=arv->dir;
      else parent->esq=arv->dir;
   }
   else if(arv->esq->dir!=NULL && arv->dir->esq!=NULL){
      status substitute=deepmost(arv);
      tree* fio=substitute.son;
      tree* pai=substitute.arv; //Só pra simplificar entendimento msm...
      if(substitute.pos<0){
         pai->dir=NULL;
         if(orig==1)
            parent->dir=fio;
         else parent->esq=fio;
      }
      else {
         pai->esq=NULL;
         if(orig==1)
            parent->dir=fio;
         else parent->esq=fio;
      }
   }
   else {
      if(arv->dir->dir!=NULL){
         if(orig==1)
            parent->dir=arv->dir->dir;
         else parent->esq=arv->dir->dir;
      }
      else if(arv->esq->esq!=NULL){
         if(orig==1)
            parent->dir=arv->dir->dir;
         else parent->esq=arv->dir->dir;
      }
      else {
         if(orig==1){
            parent->dir=arv->dir;
            arv->dir=arv->esq;
         }
         else{
            parent->esq=arv->dir;
            arv->dir=arv->esq;
         }
      }
   }
   free(arv);
}

tree *arv_cria(int c, tree *sae, tree *sad) {

	tree *p = (tree *) malloc(sizeof(tree));
	p->info = c ;
	p->esq = sae ;
	p->dir = sad ;
	return p ;
}

void test(int type){
   tree* top=arv_cria(0, NULL,NULL);
   tree* to_remove=arv_cria(1, NULL,NULL);
   tree* left=arv_cria(2, NULL,NULL);
   tree* right=arv_cria(2, NULL,NULL);
   tree* son=arv_cria(3, NULL,NULL);
   top->esq=to_remove;
   switch (type) {
      case 1: //0 filhos
         remover(to_remove, top);
         printf("Teste 1 OK\n");
         break;
      case 2: //1 filho
         to_remove->dir=right;
         remover(to_remove, top);
         printf("Teste 2 OK\n");
         break;
      case 3: //2 filhos
         to_remove->dir=right;
         to_remove->esq=left;
         left->dir=son;
         remover(to_remove, top);
         printf("Teste 2 OK\n");
         break;
   }
}

int main(){
   test(1);
   test(2);
   test(3);
   return 0;
}
