class Solution:
    def mySqrt(self, x: int) -> int:
        number=1
        while number*number<=x:
            number+=1
        return (number-1)