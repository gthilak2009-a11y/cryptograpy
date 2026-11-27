#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(void){
 char text[1000],key[200];int mode,j=0;
 printf("Text: ");fgets(text,sizeof text,stdin);
 printf("Alphabetic key: ");scanf("%199s",key);
 printf("1.Encrypt 2.Decrypt: ");scanf("%d",&mode);
 int klen=(int)strlen(key);
 for(int i=0;text[i];i++)if(isalpha((unsigned char)text[i])){
  int shift=toupper((unsigned char)key[j++%klen])-'A';
  if(mode==2)shift=26-shift;
  char b=islower((unsigned char)text[i])?'a':'A';
  text[i]=(char)(b+(text[i]-b+shift)%26);
 }
 printf("Result: %s",text);return 0;
}
