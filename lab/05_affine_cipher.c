#include <stdio.h>
#include <ctype.h>
int gcd(int a,int b){while(b){int t=a%b;a=b;b=t;}return a;}
int inv(int a){for(int x=1;x<26;x++)if((a*x)%26==1)return x;return -1;}
int main(void){
 char s[1000];int a,b,mode;
 printf("Enter text: ");fgets(s,sizeof s,stdin);
 printf("Enter a and b (gcd(a,26)=1): ");scanf("%d%d",&a,&b);
 if(gcd((a%26+26)%26,26)!=1){puts("Invalid a: it must be coprime to 26.");return 1;}
 printf("1.Encrypt 2.Decrypt: ");scanf("%d",&mode);
 int ai=inv((a%26+26)%26);
 for(int i=0;s[i];i++)if(isalpha((unsigned char)s[i])){
  int p=toupper((unsigned char)s[i])-'A',v;
  if(mode==1)v=(a*p+b)%26;else v=(ai*(p-b+260))%26;
  s[i]=(char)((islower((unsigned char)s[i])?'a':'A')+v);
 }
 printf("Result: %s",s);return 0;
}
