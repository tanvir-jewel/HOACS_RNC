#include <stdio.h>

// Function to find modular multiplicative inverse
int modInverse(int x, int m) {
    for (int i = 1; i < m; i++) {
        if ((x * i) % m == 1) {
            return i;
        }
    }
    return -1; // Return -1 if no inverse exists
}

// Function to perform division in RNC
void divideInRNC(int a[], int b[], int moduli[], int result[], int k) {
    for (int i = 0; i < k; i++) {
        int b_inv = modInverse(b[i], moduli[i]);
        if (b_inv == -1) {
            printf("Error: No modular inverse for modulus %d\n", moduli[i]);
            return; // Exit the function if no modular inverse is found
        }
        result[i] = (a[i] * b_inv) % moduli[i];
    }
}

int main() {
    // Example usage
    int a[] = {3, 4, 5}; // Operand a in RNC format
    int b[] = {2, 3, 4}; // Operand b in RNC format
    int moduli[] = {7, 11, 13}; // Moduli
    int k = sizeof(moduli) / sizeof(moduli[0]); // Number of moduli
    int result[k]; // Array to store the result

    divideInRNC(a, b, moduli, result, k);

    printf("Result of division in RNC: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}
