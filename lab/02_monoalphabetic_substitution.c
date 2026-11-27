#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(void) {
    const char alphabet[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char key[27], text[1000]; int mode;
    printf("Enter 26-letter cipher alphabet: "); scanf("%26s", key);
    if (strlen(key)!=26) { puts("Key must contain 26 letters."); return 1; }
    int seen[26]={0};
    for(int i=0;i<26;i++){ key[i]=(char)toupper((unsigned char)key[i]);
        if(key[i]<'A'||key[i]>'Z'||seen[key[i]-'A']++){puts("Invalid key: letters must be unique.");return 1;}}
    getchar(); printf("Enter text: "); fgets(text,sizeof text,stdin);
    printf("1.Encrypt 2.Decrypt: "); scanf("%d",&mode);
    for(int i=0;text[i];i++) if(isalpha((unsigned char)text[i])){
        int x=toupper((unsigned char)text[i])-'A', y=x;
        if(mode==1)y=key[x]-'A'; else {for(y=0;y<26&&key[y]-'A'!=x;y++);}
        text[i]=(char)((islower((unsigned char)text[i])?'a':'A')+y);
    }
    printf("Result: %s",text); return 0;
}
