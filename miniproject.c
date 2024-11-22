#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void base2_to_base10(int Num){


    int decimal = 0;  // Résultat in base 10
    int i = 0;        // Position du bit
   int New_num =Num;  // to save the previous number
   if(New_num < 0) { Num = -Num; } // to convert into positive if its negative


    while (Num > 0) {                    // Tant qu'il reste des bits dans le nombre binaire
        int bit = Num % 10;            // Extraire le dernier bit (0 ou 1)
        decimal += bit * pow(2,i);    // Ajouter bit * pow(2^i)

        Num /= 10;                   //pour passe a notre chiffre

        i++;

    }
  if (New_num <0 ){

      printf("The decimal value is: %d\n", -decimal);
    }else{

    printf("The decimal value is: %d\n", decimal);}




    return 0;

}

void base10_to_binary(int Num){
    int R,P,X,B;

 int New_num =Num;
   if(New_num < 0) { Num = -Num; }

          P=1; //unite place in binary
          B=0;  // binary result

     do {

        R = Num%2; // get the remainder when Num is divided by 2 ( it gives the current binary digit(extrait le dernier bit )  R means REMAINDER
        B = B+R*P;  // add the binary digit (R) at the correct place value (P)        B MEANS BINARY
        P = P*10;    // update the place of value (shift left in decimal )      P MEANS PLACE

   Num = Num/2;  //divide Num  by 2 to process to the next binary digit



     }while (Num != 0); // while the value of S not equal to 0

        if (New_num <0 ){

      printf("The Binary value is: %d\n", -B);
    }else{

    printf("The Binary value is: %d\n", B);}
}


void base10_to_base8(int num) {
    int octal = 0;   // Résultat final in base 8
    int i = 1;       // Multiplicateur pour positionner les chiffres correctement
int New_num =num;
    do {
         if(num <0){

        num=-num; }

        int remainder = num % 8;    // Reste (chiffre en base )
        octal += remainder * i;     // Construction du nombre octal
        num = num/8;                   // Réduce the numbre en divisant par 8
        i =i*10;                    // Passer à la position suivante (décalage)
    } while (num > 0);

    if (New_num <0 ){

      printf("The octal value is: %d\n", -octal);
    }else{

    printf("The octal value is: %d\n", octal);}
}

void base8_to_base10(int Num) {

int new_num = Num ;
     int decimal = 0;  // Résultat en base 10
    int i = 0;        // Position du bit

if(new_num < 0){

    Num = -Num ;
}

    // Tant qu'il reste des bits dans le nombre binaire

    while (Num > 0) {
        int bit = Num % 10;            // Extraire le dernier bit (0 ou 1)
        decimal += bit * pow(8,i);    // Ajouter bit * pow(8^i)

        Num /= 10;

        i++;

    }
    if (new_num <0 ){

      printf("The decimal value is: %d\n", -decimal);
    }else{

    printf("The decimal  value is: %d\n", decimal );}

}














   int main()
{

  int X,base1,base2 ;

   printf("please choose your base : ");
   scanf("%d",&base1);

  printf("enter your number : ");
  scanf("%d",&X);

  printf("which base do you want to convert : ");
  scanf("%d",&base2);

  if ( base1 ==10 && base2 == 2 ){


     base10_to_binary(X);}

if ( base1 == 2 && base2 == 10){


    base2_to_base10(X);

} if (base1 == 10 && base2 == 8  ){


    base10_to_base8(X); }


if (base1 == 8 && base2 == 10  ){


  base8_to_base10(X);}



    return 0;


}














