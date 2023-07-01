class Solution:
    def addBinary(self, a: str, b: str) -> str:
        result = int(a,2)+int(b,2)
    
        binary_Result=f"{result:b}"
        return binary_Result
    