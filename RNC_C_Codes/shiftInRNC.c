#include <stdio.h>
#include <math.h> // For pow function

// Function to perform shifting in RNC
void shiftInRNC(int A, int n, int moduli[], int D[], int k) {
    for (int i = 0; i < k; i++) {
        int A_i = A % moduli[i];
        // Calculate 2^n and then perform the multiplication and modulo operation
        D[i] = (int)(A_i * pow(2, n)) % moduli[i];
    }
}

int main() {
    // Example usage
    int A = 5; // Operand
    int n = 3; // Shift amount
    int moduli[] = {3, 5, 7}; // Moduli
    int k = sizeof(moduli) / sizeof(moduli[0]); // Number of moduli
    int D[k]; // Array to store result

    shiftInRNC(A, n, moduli, D, k);

    printf("Result of shifting in RNC: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", D[i]);
    }
    printf("\n");

    return 0;
}
