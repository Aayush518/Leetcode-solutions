//program to calculate partial sum
def partial_sum(n):
    sum = 0
    for i in range(1, n+1):
        sum += i
    return sum
