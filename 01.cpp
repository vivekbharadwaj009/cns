#include <stdio.h>
#include <ctype.h>

void encryptDecrypt(char text[]) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) { 
            if (isupper(text[i])) {
                text[i] = 'Z' - (text[i] - 'A');
            } 
            else if (islower(text[i])) {
                text[i] = 'z' - (text[i] - 'a');
            }
        }
    }
}

int main() {
    char message[100];

    printf("Enter the message: ");
    fgets(message, sizeof(message), stdin);

    encryptDecrypt(message);
    printf("Encrypted Message: %s", message);

    encryptDecrypt(message);
    printf("Decrypted Message: %s", message);

    return 0;
}
