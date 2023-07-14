import math

def is_fibonacci_number(x):
    # Check if x is a perfect square
    def is_perfect_square(n):
        return math.isqrt(n) ** 2 == n

    # Check if x is a Fibonacci number
    def is_fibonacci(n):
        return is_perfect_square(5 * n * n + 4) or is_perfect_square(5 * n * n - 4)

    return is_fibonacci(5 * x * x)  # Check if 5*x^2 is a Fibonacci number

# Test the function
number = int(input("Enter a number: "))
if is_fibonacci_number(number):
    print(number, "is a Fibonacci number.")
else:
    print(number, "is not a Fibonacci number.")
