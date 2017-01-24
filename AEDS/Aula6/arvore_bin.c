#include "arvore.h"

arv_bin* bin_cria(char* label){
    arv_bin* node= (arv_bin*) malloc(sizeof(arv_bin));
    node->info=(char*) malloc(sizeof(label));
    strcpy(node->info, label);
    node->left=(arv_bin*) NULL;
    node->right=(arv_bin*) NULL;
    return node;
}

void bin_print(arv_bin* top){
    if(top!=NULL){
		printf("\n  %s", top->info);
		bin_print(top->left);
		bin_print(top->right);
    }
}

arv_bin* bin_libera(arv_bin* node){
	if(node!=NULL){
        bin_libera(node->left);
        bin_libera(node->right);
        free(node);
	}
	return NULL;
}

int bin_pertence(arv_bin* node, char* label){
    if(node==NULL)
		return 0;
	else
		return strcmp(label, node->info)==0 || bin_pertence(node->left, label) || bin_pertence(node->right, label) ;
}

static int max2(int a, int b){
    return (a>b) ? a:b;
}

int bin_altura(arv_bin* node){
	if(node==NULL)
		return -1;
	else
		return 1+max2(bin_altura(node->left), bin_altura(node->right));
}

int main(){
	printf("Colé zé");

	arv_bin* my_year= bin_cria("Ariel");
	my_year->right= bin_cria("Daw");
	my_year->left=bin_cria("Not Daw");
	my_year->right->left= bin_cria("Daw");
	my_year->left->right=bin_cria("Not Daw");
	my_year->right->right= bin_cria("Daw");
	my_year->left->left=bin_cria("Not Daw");

	bin_print(my_year);
	printf("\n Pertence: %d", bin_pertence(my_year, "Daw"));
	printf("\n Altura: %d", bin_altura(my_year));
	bin_libera(my_year);
	return 0;
}
