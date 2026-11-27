#include <stdio.h>
#include <ctype.h>
#include <string.h>
int gcd(int a,int b){while(b){int t=a%b;a=b;b=t;}return a;}
int inv(int a){for(int i=1;i<26;i++)if(a*i%26==1)return i;return -1;}
int main(void){
 char c[3000];int freq[26]={0},top1=0,top2=1;
 printf("Enter affine ciphertext: ");fgets(c,sizeof c,stdin);
 for(int i=0;c[i];i++)if(isalpha((unsigned char)c[i]))freq[toupper((unsigned char)c[i])-'A']++;
 for(int i=0;i<26;i++)if(freq[i]>freq[top1])top1=i;
 top2=(top1==0?1:0);for(int i=0;i<26;i++)if(i!=top1&&freq[i]>freq[top2])top2=i;
 printf("Most frequent: %c; second: %c\n",top1+'A',top2+'A');
 /* Try common English assumptions: most frequent -> E, second -> T. */
 for(int a=1;a<26;a++)if(gcd(a,26)==1)for(int b=0;b<26;b++){
  if((a*4+b)%26==top1 && (a*19+b)%26==top2){
   int ai=inv(a);printf("Candidate a=%d b=%d: ",a,b);
   for(int i=0;c[i];i++)if(isalpha((unsigned char)c[i]))putchar('A'+(ai*(toupper((unsigned char)c[i])-'A'-b+260))%26);else putchar(c[i]);
   puts("");
  }
 }
 return 0;
}
