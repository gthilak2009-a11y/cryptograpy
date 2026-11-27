#include <stdio.h>
#include <string.h>
/* Educational CBC chaining demonstration using a reversible XOR toy block transform.
   For real security use a vetted cryptographic library and authenticated encryption. */
#define BS 8
void toy_encrypt(const unsigned char in[BS],unsigned char out[BS],const unsigned char key[BS]){
 for(int i=0;i<BS;i++)out[i]=in[i]^key[i];
}
int main(void){
 unsigned char key[BS]="CNSKEY!!",iv[BS]="INITVEC!";
 char msg[256];unsigned char prev[BS],block[BS],out[BS];
 printf("Message (max 240 chars): ");fgets(msg,sizeof msg,stdin);
 memcpy(prev,iv,BS);size_t len=strlen(msg);
 printf("CBC toy ciphertext (hex): ");
 for(size_t off=0;off<len;off+=BS){memset(block,0,BS);size_t n=len-off<BS?len-off:BS;memcpy(block,msg+off,n);
  for(int i=0;i<BS;i++)block[i]^=prev[i];toy_encrypt(block,out,key);
  for(int i=0;i<BS;i++)printf("%02X",out[i]);memcpy(prev,out,BS);
 }
 puts("\nNote: XOR toy transform is NOT 3DES and is not secure. It only illustrates CBC chaining.");
 return 0;
}
