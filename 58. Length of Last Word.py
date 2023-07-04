class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        ss=s.strip()
        a=ss.split(" ")
        return len(a[-1])