// Write a C Program to implement EAP
#include <stdio.h>
#include <string.h>

// Simulated EAP codes
#define EAP_REQUEST 1
#define EAP_RESPONSE 2
#define EAP_SUCCESS 3
#define EAP_FAILURE 4

void sendEAPMessage(int code, const char *message) {
    switch (code) {
        case EAP_REQUEST:
            printf("[EAP-Request]: %s\n", message);
            break;
        case EAP_RESPONSE:
            printf("[EAP-Response]: %s\n", message);
            break;
        case EAP_SUCCESS:
            printf("[EAP-Success]: Authentication Successful\n");
            break;
        case EAP_FAILURE:
            printf("[EAP-Failure]: Authentication Failed\n");
            break;
        default:
            printf("[Unknown EAP Code]\n");
    }
}

int main() {
    char identity[50], password[50];
    char correctIdentity[] = "student123";
    char correctPassword[] = "secure@123";

    printf("------ Simulated EAP Handshake ------\n\n");

    // Step 1: Request Identity
    sendEAPMessage(EAP_REQUEST, "Please provide your Identity.");
    printf("Enter Identity: ");
    scanf("%s", identity);
    sendEAPMessage(EAP_RESPONSE, identity);

    // Step 2: Request Password
    sendEAPMessage(EAP_REQUEST, "Please provide your Password.");
    printf("Enter Password: ");
    scanf("%s", password);
    sendEAPMessage(EAP_RESPONSE, "********");

    // Step 3: Validate and Respond
    if (strcmp(identity, correctIdentity) == 0 && strcmp(password, correctPassword) == 0) {
        sendEAPMessage(EAP_SUCCESS, "");
    } else {
        sendEAPMessage(EAP_FAILURE, "");
    }

    return 0;
}


// ------ Simulated EAP Handshake ------

// [EAP-Request]: Please provide your Identity.
// Enter Identity: student123
// [EAP-Response]: student123
// [EAP-Request]: Please provide your Password.
// Enter Password: secure@123
// [EAP-Response]: ********
// [EAP-Success]: Authentication Successful
