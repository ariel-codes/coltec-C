typedef struct Fila fila;
typedef struct Filal fila_l;
typedef struct Lista lista;

fila *fila_cria_vet();
void fila_insere_vet(fila *f, float v);
float fila_retira_vet(fila *f);
int fila_vazia_vet(fila *f);
void fila_libera_vet(fila *f);

fila_l *fila_cria_l();
void fila_insere_l(fila_l *f, char v[20]);
char *fila_retira_l(fila_l *f);
int fila_vazia_l(fila_l *f);
void fila_libera_l(fila_l *f);
void fila_imprime_l(fila_l *f);
char *fila_ultimo_l(fila_l *f);
