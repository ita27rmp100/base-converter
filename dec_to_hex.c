// function declaration :
const char* decimalTo_hex(int dec);
// function definition :
const char* decimalTo_hex(int dec){
    int digit,b,p,i;
    char digitStr[0];
    char decSTR[20];
    sprintf(decSTR,"%i",dec);
    char result[strlen(decSTR)-1];
    b=0;
    i=strlen(decSTR)-1;
    digit = 0 ;
    while(dec!=0){
        b = b + digit * p;
        p = p * 10;
        itoa((dec%16),digitStr,10);
        switch(dec%16){
            case 10 :
                digitStr[0]='A';
                break;
            case 11 :
                digitStr[0]='B';
                break;
            case 12 :
                digitStr[0]='C';
                break;
            case 13 :
                digitStr[0]='D';
                break;
            case 14 :
                digitStr[0]='E';
                break;
            case 15 :
                digitStr[0]='F';
                break;
            default :
                itoa((dec%16),digitStr,10);
                break;

        }
        result[i] = digitStr[0];
        i--;
        dec = (int)dec/16;
    }
    printf("result : %s\n",result);
    return result;
}
