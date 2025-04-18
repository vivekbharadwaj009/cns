#include <stdio.h>
#include <math.h>

// Function to compute (base^exponent) % mod using modular exponentiation
long long power(long long base, long long exponent, long long mod) {
    long long result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) { // If exponent is odd, multiply base with result
            result = (result * base) % mod;
        }
        base = (base * base) % mod; // Square the base
        exponent /= 2;
    }
    return result;
}

int main() {
    long long prime, base, privateKeyA, privateKeyB, publicKeyA, publicKeyB, sharedKeyA, sharedKeyB;

    // Input prime number and base (should be agreed upon by both parties)
    printf("Enter a prime number: ");
    scanf("%lld", &prime);
    printf("Enter a primitive root of %lld: ", prime);
    scanf("%lld", &base);

    // Private keys (chosen secretly by each user)
    printf("Enter Private Key for User A: ");
    scanf("%lld", &privateKeyA);
    printf("Enter Private Key for User B: ");
    scanf("%lld", &privateKeyB);

    // Compute public keys
    publicKeyA = power(base, privateKeyA, prime);
    publicKeyB = power(base, privateKeyB, prime);

    printf("Public Key for User A: %lld\n", publicKeyA);
    printf("Public Key for User B: %lld\n", publicKeyB);

    // Compute shared secret keys
    sharedKeyA = power(publicKeyB, privateKeyA, prime);
    sharedKeyB = power(publicKeyA, privateKeyB, prime);

    printf("Shared Secret Key for User A: %lld\n", sharedKeyA);
    printf("Shared Secret Key for User B: %lld\n", sharedKeyB);

    // Since both keys should be the same, it confirms the key exchange is successful
    if (sharedKeyA == sharedKeyB) {
        printf("Key Exchange Successful! Shared Key: %lld\n", sharedKeyA);
    } else {
        printf("Error in Key Exchange!\n");
    }

    return 0;
}
