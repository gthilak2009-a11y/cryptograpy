#include <stdio.h>
int main(void){
 puts("DES decryption uses the same Feistel rounds as encryption, but applies subkeys in reverse order.");
 puts("Encryption round order:  K1, K2, K3, ... K16");
 puts("Decryption round order:  K16, K15, K14, ... K1");
 puts("If encryption subkeys are stored in K[0] through K[15], decryption accesses K[15-round].");
 for(int r=0;r<16;r++)printf("Decryption round %2d uses K%d\n",r+1,16-r);
 puts("This program demonstrates the required reverse key schedule; it does not implement the DES block function.");
 return 0;
}
