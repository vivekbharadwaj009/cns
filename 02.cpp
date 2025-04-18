#include <stdio.h>
#include <ctype.h>

void caesarEncrypt(char text[], int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';  
            text[i] = (text[i] - base + shift) % 26 + base;  
        }
    }
}

int main() {
    char plaintext[100];
    int shift;

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("Enter the shift value: ");
    scanf("%d", &shift);

    caesarEncrypt(plaintext, shift);

    printf("Encrypted Ciphertext: %s\n", plaintext);

    return 0;
}
