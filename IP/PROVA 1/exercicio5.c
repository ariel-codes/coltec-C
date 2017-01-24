#include <stdio.h>

int main(void){
int trab1, trab2, trab3, freq, nota, Nota;
printf("Insira suas notas, trabalho e frequência (aka número de faltas): \n ");
scanf("%d %d %d %d", &trab1 , &trab2, &trab3, &freq);
nota= (trab1*3 + trab2*5 + trab3*2)/ 10;
if(freq>15)
	printf("Vc foi reprovado \n");
else if(nota<6)
	printf("Vc terá que fazer prova final aka 'Recu' \n ");
else if(nota>6)
	printf("Yay, vc foi aprovado \n");
return 0; 

}
