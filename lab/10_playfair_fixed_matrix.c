#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(void){
 const char sq[25]="MFHIKUNOPQZVWXYELARGDSTBC";char s[1000],p[1000];int n=0;
 printf("Plaintext: ");fgets(s,sizeof s,stdin);
 for(int i=0;s[i];i++)if(isalpha((unsigned char)s[i])){char c=(char)toupper((unsigned char)s[i]);p[n++]=(c=='J'?'I':c);}
 char out[2000];int o=0;
 for(int i=0;i<n;){char a=p[i++],b=(i<n?p[i]:'X');if(a==b)b='X';else if(i<n)i++;
  int x=0,y=0;while(x<25&&sq[x]!=a)x++;while(y<25&&sq[y]!=b)y++;
  if(x==25||y==25){puts("Character not found in matrix.");return 1;}
  int r1=x/5,c1=x%5,r2=y/5,c2=y%5;
  if(r1==r2){out[o++]=sq[r1*5+(c1+1)%5];out[o++]=sq[r2*5+(c2+1)%5];}
  else if(c1==c2){out[o++]=sq[((r1+1)%5)*5+c1];out[o++]=sq[((r2+1)%5)*5+c2];}
  else{out[o++]=sq[r1*5+c2];out[o++]=sq[r2*5+c1];}
 }
 out[o]=0;printf("Ciphertext: %s\n",out);return 0;
}
