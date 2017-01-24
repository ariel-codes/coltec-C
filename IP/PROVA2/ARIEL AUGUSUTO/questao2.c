# include <stdio.h>
# include <string.h>
# include <math.h>

void histograma (int AR[]){
    int um, dois, tres, quatro, A;
    for(A=0; A<25; A++){
    if(AR[A]>600 && AR[A]<700)
        um++;
    if(AR[A]>700 && AR[A]<800)
        dois++;
    if(AR[A]>800 && AR[A]<900)
        tres++;
    if(AR[A]>900 && AR[A]<1000)
        quatro++;
    }
    printf("\n 1:");
    while(um!=0){
        printf("*");
        um--;
    }
    printf("\n 2:");
    while(dois!=0){
        printf("*");
        dois--;
    }
    printf("\n 3:");
    while(tres!=0){
        printf("*");
        tres--;
    }
    printf("\n 4:");
    while(um!=0){
        printf("*");
        tres--;
    }
}

int main(){
    int A, AR[27]; // Variáveis Multiuso
    for(A=0; A<25; A++){
        AR[A]=750;
      //  while(AR[A]<= 600){
           // AR[A]=rand()%100; // Não ligo se não é aleatório...
           // }
    }
    histograma(AR);
    return 0;
}
