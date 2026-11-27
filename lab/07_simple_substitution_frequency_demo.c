#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(void){
 char c[3000];int f[26]={0},order[26],used[26]={0};
 const char english[]="ETAOINSHRDLCUMWFGYPBVKJXQZ";
 printf("Enter substitution ciphertext: ");fgets(c,sizeof c,stdin);
 for(int i=0;c[i];i++)if(isalpha((unsigned char)c[i]))f[toupper((unsigned char)c[i])-'A']++;
 for(int i=0;i<26;i++)order[i]=i;
 for(int i=0;i<26;i++)for(int j=i+1;j<26;j++)if(f[order[j]]>f[order[i]]){int t=order[i];order[i]=order[j];order[j]=t;}
 char map[26];for(int i=0;i<26;i++)map[order[i]]=english[i];
 puts("Frequency-based approximation (not guaranteed to solve the cipher):");
 for(int i=0;c[i];i++)if(isalpha((unsigned char)c[i]))putchar((islower((unsigned char)c[i])?'a':'A')+map[toupper((unsigned char)c[i])-'A']-'A');else putchar(c[i]);
 puts("");return 0;
}
