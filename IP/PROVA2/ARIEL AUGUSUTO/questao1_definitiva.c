# include <stdio.h>
# include <string.h>
# include <math.h>

int calculaMontanteCategoria(int AR[]){
    int result=0, catg=0; // Mais variáveis multiuso
    for(catg=0; catg<25; catg++){
        result=AR[catg] + result;
    }
    if(result<=15000)
        catg = 77; // "M"
    if(result>15000 && result<=21250)
        catg = 80;
    if(result>21250)
        catg = 71;
    return result;
}

int main(){
    int A, AR[27]; // Variáveis Multiuso
    for(A=0; A<25; A++){
        AR[A]=750;
      //  while(AR[A]<= 600){
           // AR[A]=rand()%100; // Não ligo se não é aleatório...
           // }
    }
    printf("%d" , calculaMontanteCategoria(AR));
    return 0;
}
