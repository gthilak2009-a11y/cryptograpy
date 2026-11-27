#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(void){
 char key[100],msg[1000],sq[25],used[26]={0}; int n=0;
 printf("Keyword: "); scanf("%99s",key);
 for(int i=0;key[i];i++){char c=(char)toupper((unsigned char)key[i]); if(c=='J')c='I';
  if(c>='A'&&c<='Z'&&!used[c-'A']){sq[n++]=c;used[c-'A']=1;}}
 for(char c='A';c<='Z';c++)if(c!='J'&&!used[c-'A'])sq[n++]=c;
 getchar();printf("Plaintext: ");fgets(msg,sizeof msg,stdin);
 char p[1000];int m=0;
 for(int i=0;msg[i];i++)if(isalpha((unsigned char)msg[i])){char c=(char)toupper((unsigned char)msg[i]);p[m++]=(c=='J'?'I':c);}
 char out[2000];int o=0;
 for(int i=0;i<m;){char a=p[i++],b=(i<m?p[i]:'X');if(a==b)b='X';else if(i<m)i++;
  int x=0,y=0;while(sq[x]!=a)x++;while(sq[y]!=b)y++;
  int r1=x/5,c1=x%5,r2=y/5,c2=y%5;
  if(r1==r2){out[o++]=sq[r1*5+(c1+1)%5];out[o++]=sq[r2*5+(c2+1)%5];}
  else if(c1==c2){out[o++]=sq[((r1+1)%5)*5+c1];out[o++]=sq[((r2+1)%5)*5+c2];}
  else{out[o++]=sq[r1*5+c2];out[o++]=sq[r2*5+c1];}
 }
 out[o]=0;printf("Ciphertext: %s\n",out);return 0;
}
