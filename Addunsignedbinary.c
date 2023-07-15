#include <stdio.h>
#include <limits.h>

// Function to convert binary to decimal
unsigned int binaryToDecimal(unsigned int binary) {
    unsigned int decimal = 0, base = 1;
    while (binary > 0) {
        decimal += (binary % 10) * base;
        binary /= 10;
        base *= 2;
    }
    return decimal;
}

int main() {
    unsigned int num1, num2, sum;

    printf("Enter the first binary number: ");
    scanf("%u", &num1);

    printf("Enter the second binary number: ");
    scanf("%u", &num2);

    // Addition without overflow
    sum = num1 + num2;
    printf("Sum without overflow: %u (Decimal: %u)\n", sum, binaryToDecimal(sum));

    // Addition with underflow
    sum = 0 - num2;
    printf("Sum with underflow: %u (Decimal: %u)\n", sum, binaryToDecimal(sum));

    // Addition with overflow
    sum = num1 + UINT_MAX - num2;
    printf("Sum with overflow: %u (Decimal: %u)\n", sum, binaryToDecimal(sum));

    return 0;
}
