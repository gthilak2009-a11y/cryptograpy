#include <stdio.h>
int main(void){
 puts("DES key schedule structure:");
 puts("1. PC-1 selects 56 bits from the 64-bit input key (parity bits are discarded).");
 puts("2. The 56 bits are split into two disjoint 28-bit halves: C0 and D0.");
 puts("3. Each round rotates C and D according to the DES shift schedule.");
 puts("4. PC-2 selects 24 bits from C and 24 bits from D, forming a 48-bit subkey.");
 puts("Thus the first 24 subkey bits come from the C half and the second 24 from the disjoint D half.");
 puts("This is a structural demonstration, not a complete DES implementation.");
 return 0;
}
