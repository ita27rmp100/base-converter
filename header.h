#ifndef _HEADER_H_
#define _HEADER_H_

// Declare functions
    // from dec to other bases
int decTo_bin_or_oct(int dec, int base);
char* decimalTo_hex(int dec);
 // from other bases to dec
int bin_or_oct_ToDec(int oob, int base);
int hex_to_dec(char hex[]);
    // between bases
int bt_oct_bin(int num, int from, int to);
int hex_to_BinOrOct(char hex[], int baseDestination);
char* BinOrOct_to_hex(int num, int from);

#endif