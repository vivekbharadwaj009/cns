#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Function to compute gcd
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to compute modular exponentiation (base^exp % mod)
long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Function to compute modular inverse using Extended Euclidean Algorithm
int mod_inverse(int e, int phi) {
    int m0 = phi, t, q;
    int x0 = 0, x1 = 1;
    if (phi == 1) return 0;
    while (e > 1) {
        q = e / phi;
        t = phi;
        phi = e % phi, e = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0) x1 += m0;
    return x1;
}

// Function to generate RSA keys
void generate_keys(int *n, int *e, int *d) {
    int p = 61, q = 53; // Example prime numbers
    *n = p * q;
    int phi = (p - 1) * (q - 1);
    
    // Choose e (Public Key exponent)
    *e = 3;
    while (gcd(*e, phi) != 1) {
        (*e)++;
    }
    
    // Compute d (Private Key exponent)
    *d = mod_inverse(*e, phi);
}

// RSA Encryption
long long encrypt(int msg, int e, int n) {
    return mod_exp(msg, e, n);
}

// RSA Decryption
long long decrypt(long long cipher, int d, int n) {
    return mod_exp(cipher, d, n);
}

int main() {
    int n, e, d;
    generate_keys(&n, &e, &d);
    
    printf("Generated RSA Keys:\n");
    printf("Public Key: (n = %d, e = %d)\n", n, e);
    printf("Private Key: (n = %d, d = %d)\n", n, d);
    
    int message = 42; // Example message
    printf("Original Message: %d\n", message);
    
    long long encrypted = encrypt(message, e, n);
    printf("Encrypted Message: %lld\n", encrypted);
    
    long long decrypted = decrypt(encrypted, d, n);
    printf("Decrypted Message: %lld\n", decrypted);
    
    return 0;
}
