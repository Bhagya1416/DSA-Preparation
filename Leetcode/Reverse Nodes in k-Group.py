# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        count=0
        ptr=head
        while ptr and count<k:
            ptr=ptr.next
            count+=1
        if count==k:
            prev=None
            curr=head
            for _ in range(k):
                next_node=curr.next
                curr.next=prev
                prev=curr
                curr=next_node
            if curr:
                head.next=self.reverseKGroup(curr,k)
            return prev
        return head
        
