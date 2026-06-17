# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
from math import ceil
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if not head or not head.next:
            return
        c=0
        temp=head
        while temp is not None:
            c+=1
            temp=temp.next
        n=ceil(c/2)
        temp=head
        for i in range(n-1):
            temp=temp.next
        curr=temp.next
        temp.next=None
        temp=curr
        prev=None
        while(temp is not None):
            temp=temp.next
            curr.next=prev
            prev=curr
            curr=temp
        curr=prev
        temp=head
        t2=None
        while(curr!=None):
            t2=temp.next
            temp.next=curr
            t3=curr.next
            curr.next=t2
            curr=t3
            temp=t2     