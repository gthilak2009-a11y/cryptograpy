#include <stdio.h>
int main(void){
 puts("ECB: each block is encrypted independently.");
 puts("A transmission error in ciphertext block C1 affects only the decrypted plaintext block P1.");
 puts("");
 puts("CBC decryption: P1 = D(C1) XOR IV; Pi = D(Ci) XOR C(i-1).");
 puts("A bit error in transmitted C1:");
 puts("- P1 is corrupted unpredictably because D(C1) changes.");
 puts("- The corresponding bit position in P2 is flipped because P2 is XORed with C1.");
 puts("- P3 and later plaintext blocks are not affected (assuming no other errors).");
 puts("");
 puts("If a bit error occurs in source plaintext P1 before encryption in CBC mode,");
 puts("it changes C1 and therefore affects the decryption of P1 and the corresponding bit in P2.");
 puts("Later ciphertext blocks are also changed during encryption because CBC chains blocks.");
 return 0;
}
