#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(void) {
    char text[1000]; int key, mode;
    printf("Enter text: "); fgets(text, sizeof text, stdin);
    printf("Key (1-25): "); scanf("%d", &key);
    printf("1.Encrypt  2.Decrypt: "); scanf("%d", &mode);
    key = ((key % 26) + 26) % 26;
    if (mode == 2) key = 26 - key;
    for (int i=0; text[i]; i++)
        if (isalpha((unsigned char)text[i])) {
            char b = isupper((unsigned char)text[i]) ? 'A' : 'a';
            text[i] = (char)(b + (text[i]-b+key)%26);
        }
    printf("Result: %s", text);
    return 0;
}
