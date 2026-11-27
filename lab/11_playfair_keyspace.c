#include <stdio.h>
#include <math.h>
int main(void){
 double log2fact=0;for(int i=2;i<=25;i++)log2fact+=log((double)i)/log(2.0);
 printf("Number of ordered 5x5 Playfair arrangements (J omitted): 25!\n");
 printf("log2(25!) = %.4f\nApproximate keyspace = 2^%.0f\n",log2fact,log2fact);
 puts("This is the raw square count; equivalent-square conventions can reduce the effective keyspace.");
 return 0;
}
