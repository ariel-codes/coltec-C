#include "arvore.h"

arv_var* var_cria(char* label){
	arv_var* node= (arv_var*) malloc(sizeof(arv_var));
    strcpy(node->label, label);
    node->prim= (arv_var*) NULL;
    node->prox= (arv_var*) NULL;
    return node;
}

void var_insere(arv_var* root, arv_var* node){
	node->prox= root->prim;
	root->prim= node;
}

void var_print(arv_var* tree){
    arv_var* node;
    printf("  %s\n", tree->label);
    for(node=tree->prim; node!=NULL; node=node->prox)
		var_print(node);
}

int var_pertence(arv_var* a, char* c){
    arv_var* p;
    if(strcmp(c, a->label)==0)
		return 1;
	else{
        for(p=a->prim; p!=NULL; p= p->prox){
			if(var_pertence(p,c))
				return 1;
        }
        return 0;
	}
}

void var_libera(arv_var* a){
    arv_var* p=a->prim;
    while(p!= NULL){
		arv_var* t=p->prox;
		var_libera(p);
		p=t;
    }
    free(a);
}
