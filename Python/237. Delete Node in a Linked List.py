class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
        
class Solution:
    def deleteNode(self, node):
        if not node:
            return
        elif not node.next:
            node = None
            return
        
        node.val = node.next.val
        delNode = node.next
        node.next = delNode.next
        delNode = None
        
        return