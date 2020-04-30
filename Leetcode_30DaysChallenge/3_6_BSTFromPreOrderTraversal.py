# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    
    def insertinBST( self, root, val ) :
        if ( root == None ) :
            return TreeNode(val) 
        if ( root.val > val ) :
            root.left = self.insertinBST(root.left,val) 
        else :
            root.right = self.insertinBST(root.right,val)
        return root
    
    def bstFromPreorder(self, preorder: List[int]) -> TreeNode:
        root = None
        for i in preorder :
            root = self.insertinBST( root,i )
        return root