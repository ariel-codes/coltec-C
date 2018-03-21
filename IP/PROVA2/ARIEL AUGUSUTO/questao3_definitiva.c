# include <stdio.h>
# include <string.h>
# include <math.h>


int main(){
    int A=1, B=1, swap=0, swap2=0, um=0, dois=0;
    while(A!=0 && B!=0){
        printf("\n Insira o numerador e divisor da fração");
        scanf("%d %d" , &A, &B);
        if(A!=0 && B!=0){
            if(A%B==0){
                um= A/B;
                dois=1;
            }
            if(B%A==0){
                um=1;
                dois=B/A;
            }
        }
        if(A!=0 && B!=0 && um==0 && dois==0){
            if(A<=B){
                while(swap<A){
                    printf("\n %d" , swap2);
                    if(A%(swap+1)==0 && B%(swap+1)==0)
                        swap2++;
                    swap++;
                }
            }
            if(A>B){
                while(swap<=B){
                    if(A%(swap+1)==0 && B%(swap+1)==0)
                        swap2++;
                    swap++;
                }
            }

        }
        um=A/(swap2+1);
        dois=B/(swap2+1);
        printf("\n %d / %d" , um, dois);
        swap=0;
        swap2=0;
        um=0;
        dois=0;
    }
    return 0;
}
