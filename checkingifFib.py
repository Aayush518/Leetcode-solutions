# write a program to check whether the number is part of fibonacci series or not and which position it is in the series


def checkFib(n):
    a = 0
    b = 1
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        for i in range(2, n):
            c = a + b
            a = b
            b = c
            if c == n:
                return i
        return -1
    
print(checkFib(8))
print(checkFib(9))
print(checkFib(10))
print(checkFib(11))
print(checkFib(12))
print(checkFib(13))
print(checkFib(14))
print(checkFib(15))
print(checkFib(16))