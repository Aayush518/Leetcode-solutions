# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isTreeSymmetric(self, leftRoot, rightRoot):
        if leftRoot is None and rightRoot is None:
            return True
        if (leftRoot is None and rightRoot is not None) or (leftRoot is not None and rightRoot is None):
            return False
        if leftRoot.val != rightRoot.val:
            return False
        return self.isTreeSymmetric(leftRoot.left, rightRoot.right) and self.isTreeSymmetric(leftRoot.right, rightRoot.left)
    def isSymmetric(self, root):
        return self.isTreeSymmetric(root.left, root.right)