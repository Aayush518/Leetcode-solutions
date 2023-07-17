#include <stdio.h>
#include <stdlib.h>

void printBinary(int num) {
    for (int i = 7; i >= 0; i--) {
        int bit = (num >> i) & 1;
        printf("%d", bit);
    }
}

int getSum(int a, int b) {
    int iteration = 1;
    
    while (b) {
        int carry = a & b; // get all carry bits (all 1&1s)
        
        printf("Iteration %d:\n", iteration);
        printf("Carry (Binary): ");
        printBinary(carry);
        printf("\nCarry (Decimal): %d\n\n", carry);
        
        a = a ^ b; // sum of disjoint bits (everything except what needs to be carried)
        printf("Partial Sum (Binary): ");
        printBinary(a);
        printf("\nPartial Sum (Decimal): %d\n\n", a);
        
        // shift carry by one, as this is how a regular sum operation works
        // the carry is moved to the next position
        b = (unsigned)carry << 1;
        printf("Shifted Carry (Binary): ");
        printBinary(b);
        printf("\nShifted Carry (Decimal): %d\n\n", b);
        
        iteration++;
    }
    
    return a;
}

int main() {
    char binary_a[9];
    char binary_b[9];

    printf("Enter the first binary number (up to 8 bits): ");
    scanf("%8s", binary_a);

    printf("Enter the second binary number (up to 8 bits): ");
    scanf("%8s", binary_b);

    int a = strtol(binary_a, NULL, 2);
    int b = strtol(binary_b, NULL, 2);

    int sum = getSum(a, b);

    char binary_sum[9];
    itoa(sum, binary_sum, 2);

    printf("Sum in binary: %s\n", binary_sum);

    return 0;
}
