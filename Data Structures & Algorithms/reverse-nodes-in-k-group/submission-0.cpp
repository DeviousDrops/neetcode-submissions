/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr=head;
        ListNode* prev=nullptr;
        int count=0;
        while(curr){
            curr=curr->next;
            count++;
        } 
        curr=head;
        while(count>=k){
            ListNode* temp=curr;
            ListNode* p=nullptr;
            ListNode* t2=curr;
            for(int i=0;i<k;i++){
                curr=curr->next;
                temp->next=p;
                p=temp;
                temp=curr;
            }if(prev)
                prev->next=p;
            else
                head=p;
            prev=t2;
            count-=k;   
        }
        if(prev)
            prev->next=curr;
        return head;
    }
};