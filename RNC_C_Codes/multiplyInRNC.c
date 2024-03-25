#include <stdio.h>

// Function to perform multiplication in RNC
void multiplyInRNC(int a[], int b[], int moduli[], int result[], int k) {
    for (int i = 0; i < k; i++) {
        result[i] = (a[i] * b[i]) % moduli[i];
    }
}

int main() {
    // Example usage
    int a[] = {1, 2, 3}; // Operand a in RNC format
    int b[] = {4, 5, 6}; // Operand b in RNC format
    int moduli[] = {7, 11, 13}; // Moduli
    int k = sizeof(moduli) / sizeof(moduli[0]); // Number of moduli
    int result[k]; // Array to store the result

    multiplyInRNC(a, b, moduli, result, k);

    printf("Result of multiplication in RNC: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}
