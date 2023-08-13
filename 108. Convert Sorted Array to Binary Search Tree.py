# def sortedArrayToBST(self, num):
#     """
#     :type nums: List[int]
#     :rtype: TreeNode
#     """
#     # Check if the input list 'num' is empty, if so, return None since there is no tree to create
#     if not num:
#         return None

#     # Calculate the index of the middle element in the sorted array 'num'
#     mid = len(num) // 2

#     # Create a new TreeNode with the value of the middle element as the root of the BST
#     root = TreeNode(num[mid])

#     # Recursively build the left subtree by calling the 'sortedArrayToBST' function on the left half of 'num'
#     root.left = self.sortedArrayToBST(num[:mid])

#     # Recursively build the right subtree by calling the 'sortedArrayToBST' function on the right half of 'num'
#     root.right = self.sortedArrayToBST(num[mid+1:])

#     # Return the root of the BST
#     return root# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        if len(nums)==0:
            return
        ind=len(nums)//2            #Because the arr or list is shorted you should thake middle number as the root
        root=TreeNode(nums[ind])    #Now you can assign the left branch and perform recurtion with left remaining list
        root.left=self.sortedArrayToBST(nums[:ind])     #Same for the right remaining list
        root.right=self.sortedArrayToBST(nums[ind+1:])
        return root

        
