#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(void){
 char s[3000];double score[26];const double f[26]={8.2,1.5,2.8,4.3,12.7,2.2,2.0,6.1,7.0,0.15,0.77,4.0,2.4,6.7,7.5,1.9,0.095,6.0,6.3,9.1,2.8,0.98,2.4,0.15,2.0,0.074};
 printf("Ciphertext: ");fgets(s,sizeof s,stdin);
 for(int k=0;k<26;k++){score[k]=0;for(int i=0;s[i];i++)if(isalpha((unsigned char)s[i])){int p=(toupper((unsigned char)s[i])-'A'-k+26)%26;score[k]+=f[p];}}
 for(int rank=0;rank<10;rank++){int best=-1;for(int k=0;k<26;k++)if(score[k]>=0&&(best<0||score[k]>score[best]))best=k;
  if(best<0)break;printf("Candidate shift %d: ",best);
  for(int i=0;s[i];i++)if(isalpha((unsigned char)s[i]))putchar('A'+(toupper((unsigned char)s[i])-'A'-best+26)%26);else putchar(s[i]);
  score[best]=-1e9;puts("");
 }return 0;
}
