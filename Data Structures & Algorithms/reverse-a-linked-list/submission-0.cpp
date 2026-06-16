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
    ListNode* reverseList(ListNode* head) {
        ListNode* t1=nullptr;
        ListNode* t2=nullptr;
        while(head!=nullptr){
            t1=head->next;
            head->next=t2;
            t2=head;
            head=t1;
        }    
        return t2;
    }
};