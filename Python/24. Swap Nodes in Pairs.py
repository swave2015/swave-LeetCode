class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        dummyHead = ListNode(0)
        p = dummyHead
        p.next = head
        
        while p.next is not None and p.next.next is not None:
            node1 = p.next
            node2 = p.next.next
            node1.next = node2.next
            node2.next = node1
            p.next = node2
            p = node1
        
        retNode = dummyHead.next
        dummyHead.next = None
        
        return retNode