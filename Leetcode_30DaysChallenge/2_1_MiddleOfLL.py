# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

def middleNode(self, head):
    """
    :type head: ListNode
    :rtype: ListNode
    """
    fast = head ;
    slow = head ;
    while ( fast != None and fast.next != None ) :
        slow = slow.next 
        fast = (fast.next).next
    return slow