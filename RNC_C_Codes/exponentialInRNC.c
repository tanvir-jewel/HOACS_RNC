#include <stdio.h>

// Function to perform RNS multiplication
void RNSMultiply(int result[], int a[], int multiplier[], int moduli[], int k) {
    for (int i = 0; i < k; i++) {
        result[i] = (a[i] * multiplier[i]) % moduli[i];
    }
}

// Function to perform exponential operation in RNC
void exponentialInRNC(int a[], int n, int moduli[], int result[], int k) {
    // Initialize result as RNC representation of 1
    for (int i = 0; i < k; i++) {
        result[i] = 1;
    }

    // Temporary array to hold current multiplier, which is 'a' in RNC
    int tempMultiplier[k];
    for (int i = 0; i < k; i++) {
        tempMultiplier[i] = a[i];
    }

    // Repeatedly multiply 'result' by 'a' using RNS multiplication
    for (int i = 0; i < n; i++) {
        RNSMultiply(result, result, tempMultiplier, moduli, k);
    }
}

int main() {
    int a[] = {2, 2, 2}; // Operand a in RNC format, representing '2' in RNC
    int n = 3; // Exponent
    int moduli[] = {3, 5, 7}; // Moduli
    int k = sizeof(moduli) / sizeof(moduli[0]); // Number of moduli
    int result[k]; // Array to store the result

    exponentialInRNC(a, n, moduli, result, k);

    printf("Result of %d^%d in RNC: ", 2, n);
    for (int i = 0; i < k; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}
