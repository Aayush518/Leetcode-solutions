#include <stdio.h>
#include <stdlib.h>

int getSum(int a, int b) {
    while(b)
    {
        int carry = a & b; // get all carry bits (all 1&1s)
        
        a = a^b; // sum of disjoint bits (everything except what needs to be carried)
        
        // shift carry by one, as this is how a regular sum operation works
        // the carry is moved to the next position
        b = (unsigned)carry << 1; 
        
    }
    return a;
}

int main() {
    char binary_a[33];
    char binary_b[33];

    printf("Enter the first binary number (up to 32 bits): ");
    scanf("%32s", binary_a);

    printf("Enter the second binary number (up to 32 bits): ");
    scanf("%32s", binary_b);

    int a = strtol(binary_a, NULL, 2);
    int b = strtol(binary_b, NULL, 2);

    int sum = getSum(a, b);

    char binary_sum[33];
    itoa(sum, binary_sum, 2);

    printf("Sum in binary: %s\n", binary_sum);

    return 0;
}
