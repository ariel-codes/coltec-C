# include <stdio.h>
# include <string.h>
# include <math.h>

int main(){
    char A[100];
    int count;
    fgets(A[100]);
    for(count=0; count<100; count++){
    if(A[count]==97 || A[count]==101 || A[count]==105 || A[count]==111 || A[count]== 117)
        A[count]=A[count]-32;
    }
    puts(A);
    return 0;
}
