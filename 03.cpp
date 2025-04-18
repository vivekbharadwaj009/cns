#include <bits/stdc++.h>
#include <stdio.h>

// Initial Permutation Table (IP)
int IP[64] = {  
    58, 50, 42, 34, 26, 18, 10, 2,  
    60, 52, 44, 36, 28, 20, 12, 4,  
    62, 54, 46, 38, 30, 22, 14, 6,  
    64, 56, 48, 40, 32, 24, 16, 8,  
    57, 49, 41, 33, 25, 17, 9, 1,  
    59, 51, 43, 35, 27, 19, 11, 3,  
    61, 53, 45, 37, 29, 21, 13, 5,  
    63, 55, 47, 39, 31, 23, 15, 7  
};

// Feistel Function (Simplified XOR-based)
unsigned long feistel_function(unsigned long right, unsigned long key) {
    return right ^ key; // Simple XOR operation (real DES uses Expansion, S-box, P-box)
}

// Function to apply Initial Permutation (IP)
void initial_permutation(unsigned char input[8], unsigned char output[8]) {
    int i;
    
    // Initialize output to zero to prevent garbage values
    for (i = 0; i < 8; i++) {
        output[i] = 0;
    }

    // Apply permutation based on the IP table
    for (i = 0; i < 64; i++) {
        int bit_position = IP[i] - 1; // Convert from 1-based to 0-based index
        int byte_index = bit_position / 8;
        int bit_index = bit_position % 8;

        // Check if the bit is set in input, then set the corresponding output bit
        if (input[byte_index] & (1 << (7 - bit_index))) {
            output[i / 8] |= (1 << (7 - (i % 8))); // Set the bit in output
        }
    }
}

// Main DES function
void des_encrypt(unsigned long plaintext, unsigned long key) {
    unsigned char input[8], output[8];  
    int i;

    // Convert plaintext to byte array
    for (i = 0; i < 8; i++)
        input[i] = (plaintext >> (56 - i * 8)) & 0xFF;

    // Apply Initial Permutation (IP)
    initial_permutation(input, output);

    // Convert permuted output back to 64-bit integer
    unsigned long permuted_plaintext = 0;
    for (i = 0; i < 8; i++)
        permuted_plaintext |= ((unsigned long)output[i] << (56 - i * 8));

    // Split into left and right halves
    unsigned long left = (permuted_plaintext >> 32) & 0xFFFFFFFF;
    unsigned long right = permuted_plaintext & 0xFFFFFFFF;

    printf("\nAfter Initial Permutation: L0 = %08lX, R0 = %08lX", left, right);

    // 16 Rounds of Feistel Function
    for (i = 0; i < 16; i++) {
        unsigned long temp = right;
        right = left ^ feistel_function(right, key); // Apply Feistel function
        left = temp;

        printf("\nRound %2d: L = %08lX, R = %08lX", i + 1, left, right);
    }

    // Combine left and right halves
    unsigned long ciphertext = (right << 32) | left;
    printf("\nCiphertext: %08lX\n", ciphertext);
}

// Main function
int main() {
    unsigned long plaintext = 0x0123456789ABCDEF;  // 64-bit input
    unsigned long key = 0x133457799BBCDFF1;       // 64-bit key

    printf("Original Plaintext: %08lX\n", plaintext);

    des_encrypt(plaintext, key);
}
