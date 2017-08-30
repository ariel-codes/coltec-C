#include "arvore.h"
#define N 4

typedef struct arvore_fixed{
	char* label;
	struct arvore_fixed* child[N];
} arv_fix;
