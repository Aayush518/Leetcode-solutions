#include <stdio.h>

// Function to perform binary multiplication using Booth's algorithm
unsigned int boothMultiplication(unsigned int multiplicand, unsigned int multiplier) {
    unsigned int result = 0; // Accumulator

    while (multiplier != 0) {
        if (multiplier & 1) {
            result += multiplicand;
        }

        multiplicand <<= 1;
        multiplier >>= 1;
    }

    return result;
}

int main() {
    unsigned int multiplicand, multiplier;

    printf("Enter multiplicand (in binary): ");
    scanf("%u", &multiplicand);

    printf("Enter multiplier (in binary): ");
    scanf("%u", &multiplier);

    unsigned int product = boothMultiplication(multiplicand, multiplier);
    printf("Result: %u x %u = %u\n", multiplicand, multiplier, product);

    return 0;
}
