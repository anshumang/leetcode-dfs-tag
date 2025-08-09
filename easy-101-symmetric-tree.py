class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if not root:
            return True
        return self.isMirror(root.left, root.right)
    
    def isMirror(self, a: TreeNode, b: TreeNode) -> bool:
        if not a and not b:
            return True
        if not a or not b:
            return False
        return (a.val == b.val and
                self.isMirror(a.left, b.right) and
                self.isMirror(a.right, b.left))

from collections import deque

class SolutionIter:
    def isSymmetric(self, root: TreeNode) -> bool:
        if not root:
            return True
        
        q = deque([(root.left, root.right)])
        
        while q:
            a, b = q.popleft()
            if not a and not b:
                continue
            if not a or not b:
                return False
            if a.val != b.val:
                return False
            
            # mirror pairing
            q.append((a.left, b.right))
            q.append((a.right, b.left))
        
        return True
