#include "header.h"
// the C libs that we need in this project 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
// definition of the functions we declared in 'header.h'

int hex_to_dec(char hex[]){
    int i ;
    int y =0;
    int p ;
    int dec = 0;
    int digit = 0;
     int is_negative = 0;
    int len;
     if (hex[0] == '-'){
        is_negative = 1;
        // Move the pointer to skip the '-' sign
        hex++;
        len--;  
    }

    for(i=strlen(hex)-1;i>=0;i--){
        if (hex[i] >= '0' && hex[i] <= '9') {
            digit = hex[i] - '0'; // Convert '9'-'0' to 9-10
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            digit = hex[i] - 'A' + 10;  // Convert 'A'-'F' to 10-15
        } else {
            break;
        }
        p = pow(16,y);
        dec += digit*p;
        y++;
    }
        if (is_negative) {
        dec = -dec;}

    return dec ;
}


int hex_to_BinOrOct(char hex[],int baseDestination){
    int toDec = hex_to_dec(hex);
    int toDestination = decTo_bin_or_oct(toDec,baseDestination);
    return toDestination ;
}
char* BinOrOct_to_hex(int num,int from){
    static char toDestination[255] ;
    int toDec = bin_or_oct_ToDec(num,from);

    strcpy(toDestination,decimalTo_hex(toDec)); //copy the result - of converting from dec to hex - into toDestination
    return toDestination ;
}

int bin_or_oct_ToDec(int oob,int base){
    //oob means : octal or binary
    int i = 0 ;
    int dec = 0 ;
    int r , p;
    while(oob!=0){
        p = pow(base,i);
        if(oob%10 < base){
            dec += oob%10 * p ;
            oob = (int)oob/10;
            i++; 
        }
        else{
            printf("Error , digits of number must be less then %i",base);
            break;
        }
    }
    return dec;
}

char* decimalTo_hex(int dec){
    int i = 0;
    char digitStr[1];
    static char result[20] ;

    while(dec != 0){
        int reminder = dec%16;
        if (reminder < 10){
            digitStr[0] = reminder + '0';
         }
        else{
            digitStr[0] = reminder - 10 + 'A';
        }
        result[i] = digitStr[0];
        i++;
        dec = dec / 16;
    }
    result[i] = '\0' ;
    return strrev(result);
}

int decTo_bin_or_oct(int dec,int base){
    int r,p,b;
    p =1 ;
    b = 0;
    if(base==2 || base==8){
        while(dec!=0){
            r = dec % base ;
            b = b + r * p;
            p = p * 10;
            dec = (int)dec/base;
        }
    }
    return b;
}

int bt_oct_bin(int num,int from ,int to){
    int fromConvert = bin_or_oct_ToDec(num,from);
    int toDestination = decTo_bin_or_oct(fromConvert,to);
    return toDestination ;
}