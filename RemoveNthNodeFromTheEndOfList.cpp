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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
     ListNode *temp=head;
     ListNode *prev=nullptr;
     int c=0;
     if(head==nullptr){
        return nullptr;
     }
     while(temp!=nullptr){
        c++;
        temp=temp->next;
     } 
     if(n>c){
        return head;
     }
     if(n==c){
        return head->next;
     }
     else{
        ListNode *curr=head;
        for(int i=0;i<c-n;i++){
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        return head;
     }
    }
};
