#include <stdio.h>
int main (void){

int pag;
printf("Forma de Pagamento:\n 1. A vista. \n 2. Cheque para trinta dias.\n 3. Em duas vezes. \n 4. Em tres vezes \n Entre com sua opção: \n");
scanf("%d" , &pag);
if(pag>4 || pag<1)
printf("Opção inválida \n");
switch (pag){
	case 1 : 
	printf("Desconto de 20\% \n");
	break;
	case 2 :
	case 3 :
	printf("Mesmo preço a vista \n");
	break;
	case 4 :
	printf("Juros mensais de 3\% \n");
	break;
	}
return 0;
}
