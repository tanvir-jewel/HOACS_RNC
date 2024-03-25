#include <stdio.h>

// Function to convert a number into its RNC representation
void convertToRNC(int a, int moduli[], int rnc[], int k) {
    for (int i = 0; i < k; i++) {
        rnc[i] = a % moduli[i];
    }
}

int main() {
    int a = 123; // The number to be converted into RNC
    int moduli[] = {3, 5, 7, 11}; // Moduli
    int k = sizeof(moduli) / sizeof(moduli[0]); // Number of moduli
    int rnc[k]; // Array to store the RNC representation

    convertToRNC(a, moduli, rnc, k);

    printf("RNC representation of %d: ", a);
    for (int i = 0; i < k; i++) {
        printf("%d ", rnc[i]);
    }
    printf("\n");

    return 0;
}
