#include <stdio.h>

// Function to print binary representation of an 8-bit integer
void binout(int in) {
    for (int i = 7; i >= 0; i--)
        printf("%d", (in >> i) & 1);
}

int main() {
    int dividend, divisor;
    printf("Enter two numbers for division (Both must be less than 256):\n");
    printf("Enter Dividend: ");
    scanf("%d", &dividend);
    printf("Enter Divisor: ");
    scanf("%d", &divisor);

    // Initialize variables for the division process
    unsigned char A = 0;
    unsigned char Q = dividend;
    unsigned char M = divisor;
    unsigned char quotient, remainder;

    // Perform binary division using the restoring method
    for (int i = 0; i < 8; i++) {
        // Shift A and Q left by one bit
        A = (A << 1) | ((Q >> 7) & 1);
        Q = (Q << 1) | ((A >= M) ? 0 : 1);

        // Subtract M from A if necessary
        if (A >= M) {
            A -= M;
            Q |= 1; // Set q_0 to 1
        } else {
            Q &= ~1; // Set q_0 to 0
        }
    }

    // Store the final quotient and remainder in separate variables
    quotient = Q;
    remainder = A;

    // Print binary representations of the dividend and divisor
    printf("\nBinary Equivalents are:\n");
    printf("Dividend = ");
    binout(dividend);
    printf("\nDivisor = ");
    binout(divisor);
    printf("\n\n");

    // Print the quotient and remainder in decimal form
    printf("Quotient is = %d\n", quotient);
    printf("Remainder is = %d\n", remainder);

    return 0;
}
