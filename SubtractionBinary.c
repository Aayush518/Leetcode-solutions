#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getSum(int a, int b) {
    int carry = 0;
    while (b) {
        carry = a & b;
        a = a ^ b;
        b = (unsigned)carry << 1;
    }
    return a;
}

int main() {
    char binary_a[9], binary_b[9];
    printf("Enter 1st binary number: ");
    scanf("%8s", binary_a);

    printf("\nEnter 2nd binary number: ");
    scanf("%8s", binary_b);
    int a = strtol(binary_a, NULL, 2);
    int b = strtol(binary_b, NULL, 2);
    int c = (~b) + 1;

    char binary_difference[9];
    int z = getSum(a, c);
    printf("The difference in decimal is %d\n", z);
    
    itoa(z, binary_difference, 2);

    printf("The difference in binary is %s\n", binary_difference);
    

    return 0;
}
