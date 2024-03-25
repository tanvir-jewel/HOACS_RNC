#include <stdio.h>

// Function to perform addition in RNC
void addInRNC(int A, int B, int moduli[], int C[], int k) {
    for (int i = 0; i < k; i++) {
        int A_i = A % moduli[i];
        int B_i = B % moduli[i];
        C[i] = (A_i + B_i) % moduli[i];
    }
}

int main() {
    // Example usage
    int A = 14; // First operand
    int B = 15; // Second operand
    int moduli[] = {3, 5, 7}; // Moduli
    int k = sizeof(moduli) / sizeof(moduli[0]); // Number of moduli
    int C[k]; // Array to store result

    addInRNC(A, B, moduli, C, k);

    printf("Result in RNC: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", C[i]);
    }
    printf("\n");

    return 0;
}
