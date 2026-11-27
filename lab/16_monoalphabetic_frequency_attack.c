#include <stdio.h>
#include <ctype.h>
int main(void){
 char s[3000],map[26];int f[26]={0},idx[26];const char english[]="ETAOINSHRDLCUMWFGYPBVKJXQZ";
 printf("Ciphertext: ");fgets(s,sizeof s,stdin);
 for(int i=0;i<26;i++)idx[i]=i;
 for(int i=0;s[i];i++)if(isalpha((unsigned char)s[i]))f[toupper((unsigned char)s[i])-'A']++;
 for(int i=0;i<26;i++)for(int j=i+1;j<26;j++)if(f[idx[j]]>f[idx[i]]){int t=idx[i];idx[i]=idx[j];idx[j]=t;}
 for(int i=0;i<26;i++)map[idx[i]]=english[i];
 puts("Heuristic frequency substitution (manual refinement may be needed):");
 for(int i=0;s[i];i++)if(isalpha((unsigned char)s[i]))putchar((islower((unsigned char)s[i])?'a':'A')+map[toupper((unsigned char)s[i])-'A']-'A');else putchar(s[i]);
 puts("");return 0;
}
