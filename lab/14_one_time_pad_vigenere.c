#include <stdio.h>
#include <ctype.h>
int main(void){
 char s[1000];int key[1000],n=0,mode;
 printf("Text: ");fgets(s,sizeof s,stdin);
 printf("Enter number of key values (one per letter): ");scanf("%d",&n);
 if(n<1||n>999)return 1;
 printf("Enter %d key values (0-25): ",n);for(int i=0;i<n;i++){scanf("%d",&key[i]);if(key[i]<0||key[i]>25){puts("Keys must be 0..25.");return 1;}}
 printf("1.Encrypt 2.Decrypt: ");scanf("%d",&mode);
 int j=0;for(int i=0;s[i];i++)if(isalpha((unsigned char)s[i])){
  if(j>=n){puts("\nNot enough key values.");return 1;}
  int x=toupper((unsigned char)s[i])-'A';x=(x+(mode==1?key[j]:26-key[j]))%26;
  s[i]=(char)((islower((unsigned char)s[i])?'a':'A')+x);j++;
 }
 printf("Result: %s",s);return 0;
}
