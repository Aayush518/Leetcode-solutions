#include <stdio.h>

int main() {
    signed int num1 = -10;     // Positive number
    signed int num2 = -20;     // Positive number
    signed int result = num1 + num2;

    printf("Result: %d\n", result);

    // Check for overflow
    if ((num1 > 0 && num2 > 0 && result < 0) || (num1 < 0 && num2 < 0 && result > 0)) {
        printf("Overflow occurred!\n");
    }

    return 0;
}
