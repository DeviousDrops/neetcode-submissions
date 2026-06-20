# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        head=ListNode(10001)
        temp=head
        while len(lists):
            m=head
            c=0
            k=-1
            for i in range(len(lists)):
                if(not lists[i]):
                    c+=1
                    continue
                if lists[i].val<m.val:
                    m=lists[i]
                    k=i
            if c==len(lists):
                break
            lists[k]=m.next
            temp.next=m
            temp=temp.next
        return head.next

                
                
                

            
        