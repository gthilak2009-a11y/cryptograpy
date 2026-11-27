#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(void){
 char key[100],ct[1000],sq[25],used[26]={0};int n=0;
 printf("Keyword used for encryption: ");scanf("%99s",key);
 for(int i=0;key[i];i++){char c=(char)toupper((unsigned char)key[i]);if(c=='J')c='I';if(c>='A'&&c<='Z'&&!used[c-'A']){sq[n++]=c;used[c-'A']=1;}}
 for(char c='A';c<='Z';c++)if(c!='J'&&!used[c-'A'])sq[n++]=c;
 getchar();printf("Ciphertext (even number of letters): ");fgets(ct,sizeof ct,stdin);
 char p[1000];int o=0;
 for(int i=0;ct[i];i++)if(isalpha((unsigned char)ct[i]))p[o++]=(char)toupper((unsigned char)ct[i]);
 if(o%2){puts("Ciphertext must have an even number of letters.");return 1;}
 for(int i=0;i<o;i+=2){int x=0,y=0;while(x<25&&sq[x]!=p[i])x++;while(y<25&&sq[y]!=p[i+1])y++;if(x==25||y==25){puts("Invalid ciphertext.");return 1;}
  int r1=x/5,c1=x%5,r2=y/5,c2=y%5;
  if(r1==r2){p[i]=sq[r1*5+(c1+4)%5];p[i+1]=sq[r2*5+(c2+4)%5];}
  else if(c1==c2){p[i]=sq[((r1+4)%5)*5+c1];p[i+1]=sq[((r2+4)%5)*5+c2];}
  else{p[i]=sq[r1*5+c2];p[i+1]=sq[r2*5+c1];}
 }
 p[o]=0;printf("Decrypted text (remove filler X where appropriate): %s\n",p);return 0;
}
