#include <stdio.h>
#include <ctype.h>
#include <string.h>
int inv(int a){for(int i=1;i<26;i++)if(a*i%26==1)return i;return -1;}
int main(void){
 char s[1000];int mode;const int a=9,b=4,c=5,d=7;
 int det=(a*d-b*c+2600)%26,di=inv(det);
 if(di<0){puts("Key matrix is not invertible modulo 26.");return 1;}
 printf("Text (letters only are processed): ");fgets(s,sizeof s,stdin);
 printf("1.Encrypt 2.Decrypt: ");scanf("%d",&mode);
 char p[1000];int n=0;for(int i=0;s[i];i++)if(isalpha((unsigned char)s[i]))p[n++]=(char)toupper((unsigned char)s[i]);
 if(n%2)p[n++]='X';
 for(int i=0;i<n;i+=2){int x=p[i]-'A',y=p[i+1]-'A',u,v;
  if(mode==1){u=(a*x+b*y)%26;v=(c*x+d*y)%26;}
  else{u=(di*(d*x-b*y+2600))%26;v=(di*(-c*x+a*y+2600))%26;}
  p[i]='A'+u;p[i+1]='A'+v;
 }
 p[n]=0;printf("Result: %s\n",p);return 0;
}
