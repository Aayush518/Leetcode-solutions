#include<stdio.h>

int main()
{
    int num1, num2, sum, carry;
    printf("Enter two numbers &num1, &num2: ");
    scanf("%d %d", &num1, &num2);

    while (num2 != 0)
    {
        sum = num1 ^ num2; //SUM of two integer is num1 XOR num2
        carry = (num1 & num2) << 1; //CARRY of two integer is num1 AND num2
        num1 = sum;
        num2 = carry;
    }
    printf("Sum = %d", sum);
// display the sum in binary form
    printf("\nSum in binary form = ");
    while (sum != 0)
    {
        printf("%d", sum % 2);
        sum /= 2;
    }
    return 0;
}