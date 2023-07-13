class Solution:
    def myPow(self, x: float, n: int) -> float:
        # base cases
        if n == 0:
            return 1
        if n < 0:
            n = -n
            x = 1 / x
        
        # initialize result with 1
        result = 1
        
        # calculate x^n
        while n:
            # if n is odd, multiply result with x
            if n % 2 == 1:
                result *= x
            
            # multiply x with itself
            x *= x
            
            # divide n by 2
            n = n // 2
        
        return result