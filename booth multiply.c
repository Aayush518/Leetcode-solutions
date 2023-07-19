#include <stdio.h>

// Function to perform binary multiplication using Booth's algorithm
unsigned int boothMultiplication(unsigned int multiplicand, unsigned int multiplier) {
    unsigned int result = 0; // Accumulator
    int bit = 0; // LSB of the multiplier

    while (multiplier != 0) {
        int lsb = multiplier & 1; // Get the least significant bit of the multiplier

        if (lsb == 1 && bit == 0) {
            result += multiplicand;
        } else if (lsb == 0 && bit == 1) {
            result -= multiplicand;
        }

        multiplicand <<= 1; // Shift the multiplicand to the left by 1
        bit = lsb; // Update the bit for the next iteration
        multiplier >>= 1; // Shift the multiplier to the right by 1
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
