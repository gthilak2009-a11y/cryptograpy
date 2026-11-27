#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(void){
 char key[100],map[27],text[1000];int seen[26]={0},n=0,mode;
 printf("Keyword: ");scanf("%99s",key);
 for(int i=0;key[i];i++){char c=(char)toupper((unsigned char)key[i]);if(c>='A'&&c<='Z'&&!seen[c-'A']){map[n++]=c;seen[c-'A']=1;}}
 for(char c='A';c<='Z';c++)if(!seen[c-'A'])map[n++]=c;map[26]=0;
 getchar();printf("Text: ");fgets(text,sizeof text,stdin);printf("1.Encrypt 2.Decrypt: ");scanf("%d",&mode);
 for(int i=0;text[i];i++)if(isalpha((unsigned char)text[i])){
  int x=toupper((unsigned char)text[i])-'A',y=x;
  if(mode==1)y=map[x]-'A';else for(y=0;y<26&&map[y]-'A'!=x;y++);
  text[i]=(char)((islower((unsigned char)text[i])?'a':'A')+y);
 }
 printf("Cipher alphabet: %s\nResult: %s",map,text);return 0;
}
