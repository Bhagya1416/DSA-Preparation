import heapq
from typing import List, Optional
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        counter=0
        min_heap=[]
        for head in lists:
            if head:
                heapq.heappush(min_heap,(head.val,counter,head))
                counter+=1
        dummy=ListNode(0)
        current=dummy
        while min_heap:
            val,_,node=heapq.heappop(min_heap)
            current.next=node
            current=current.next
            if node.next:
                heapq.heappush(min_heap,(node.next.val, counter, node.next))
                counter+=1
        return dummy.next

        
