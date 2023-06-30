class Solution:
    def isPalindrome(self, x: int) -> bool:
        sum1=0
        rev=0
        abc=x
        while(x>0):
            last_digit = x%10
            rev = rev*10 + last_digit
            x=x//10
        if rev==abc:
            return True
        else:
            return False
