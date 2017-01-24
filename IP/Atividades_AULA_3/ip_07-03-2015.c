#include <stdio.h>

main()
{
   float a, b, c, d, e, f ;
   // Ex4-a
   printf ( "\n Insira a temperatura a ser convertida:");
   scanf( "%f", &a);
   a=(9*a+160)/5 ;
   printf("\n %.2f Celsius" , a );
   // Ex4-b 
   printf("\n Insira a altura e raio do cilindro: ");
   scanf("%f %f" , &a , &b);
   a= a*a*b*3.14;
   printf("Volume: %f" , a );
   // Ex4-c
   printf("\n Insira a largura, profundidade e comprimento da caixa:");
   scanf("%f %f %f" , &a, &b, &c);
   a= a*b*c ;
   printf("Volume: %.2f" , a);
   // Ex6
   int int1, int2, int3, int4, int5 ;
   printf("\n Insira 5 valores inteiros:");
   scanf("%d %d %d %d %d" , &int1, &int2, &int3, &int4, &int5);
   int1= int1+int2+int3+int4+int5;
   printf("\n Soma: %d " , int1);
   // Ex7
   printf("\n Insira 5 valores reais:");
   scanf("%f %f %f %f %f %f " , &a, &b, &c, &d, &f, &e);
   a= (a+b+c+d+e+f)/6;
   printf("\n Media aritmetica: %f" , a);
   // Ex8
   int1 =  1 + 1/2 + 1/3 + 1/4 + 1/5 ;
   printf("\n H= %d" , int1);
   // Ex9
   printf("\n Insira seu salario atual e a porcentagem de aumento:");
   scanf("%f %f" , &a, &b);
   a= a*((b+100)/100);
   printf("\n Novo salario: %f" , a);
   //Ex10
   printf("\n Insira suas 3 notas:");
   scanf("%f %f %f" , &a, &b, &c);
   a = (a*4+b*3+c*3)/10;
   printf("\n Sua nota e: %.2f" , a);
   // Mds, quase esqueci que tinha de enviar [11:00 07/03]...
   return 0;
   
}