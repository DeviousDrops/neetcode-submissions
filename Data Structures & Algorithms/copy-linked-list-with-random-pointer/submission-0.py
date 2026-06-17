"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if not head:
            return None
        temp=head.next
        n=Node(head.val)
        k=n
        d={head:0}
        l=[n]
        i=1
        while(temp):
            n.next=Node(temp.val)
            d[temp]=i
            n=n.next
            l.append(n)
            temp=temp.next
            i+=1
        n=k
        l.append(None)
        d[None]=len(l)-1
        for j in range(i):
           n.random=l[d[head.random]]
           n=n.next
           head=head.next
        return k 
        