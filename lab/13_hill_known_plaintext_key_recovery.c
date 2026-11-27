#include <stdio.h>
int inv(int a){for(int i=1;i<26;i++)if(((a%26+26)%26)*i%26==1)return i;return -1;}
int mod(int x){return (x%26+26)%26;}
int main(void){
 int p[4],c[4];puts("Enter 4 plaintext numbers (A=0...Z=25), then corresponding 4 ciphertext numbers.");
 for(int i=0;i<4;i++)scanf("%d",&p[i]);for(int i=0;i<4;i++)scanf("%d",&c[i]);
 /* Columns are two plaintext/ciphertext digraphs. */
 int det=mod(p[0]*p[3]-p[1]*p[2]),di=inv(det);
 if(di<0){puts("Plaintext matrix is not invertible modulo 26; choose different known pairs.");return 1;}
 int ia=mod(di*p[3]),ib=mod(-di*p[1]),ic=mod(-di*p[2]),id=mod(di*p[0]);
 int k[4]={mod(c[0]*ia+c[1]*ic),mod(c[0]*ib+c[1]*id),mod(c[2]*ia+c[3]*ic),mod(c[2]*ib+c[3]*id)};
 printf("Recovered Hill key matrix:\n%d %d\n%d %d\n",k[0],k[1],k[2],k[3]);return 0;
}
