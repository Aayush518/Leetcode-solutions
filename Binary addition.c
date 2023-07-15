
#include <stdio.h>
#include <limits.h>

// function to add two unsigned binary numbers
unsigned int add(unsigned int num1, unsigned int num2) {
    unsigned int carry = 0, sum = 0, bit1, bit2;

    while (num1 > 0 || num2 > 0) {
        bit1 = num1 & 1;    // get the rightmost bit of num1
        bit2 = num2 & 1;    // get the rightmost bit of num2

        // logic for sum of 3 bits
        sum = sum | ((bit1 ^ bit2 ^ carry) << 1);

        // logic for the carry
        carry = (bit1 & bit2) | (bit1 & carry) | (bit2 & carry);

        num1 = num1 >> 1;   // right shift num1 by 1 bit
        num2 = num2 >> 1;   // right shift num2 by 1 bit
    }

    // if overflow, then add a leading 1
    if (carry)
        sum = sum | (1 << 1);

    return sum;
}

int main() {
    unsigned int num1, num2, sum;

    printf("Enter the first binary number: ");
    scanf("%u", &num1);

    printf("Enter the second binary number: ");
    scanf("%u", &num2);

    sum = add(num1, num2);
    printf("Sum: %u\n", sum);

    return 0;
}   // end of main()