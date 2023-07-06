class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        char = set()
        p = 0
        while(p<len(nums)):
            if(nums[p] in char):
                nums.remove(nums[p])
            else:
                char.add(nums[p])
                p = p+1
                
        #print(nums)
        return len(char)