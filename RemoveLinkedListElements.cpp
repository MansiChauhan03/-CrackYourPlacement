class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
      if(head==nullptr){
        return nullptr;
      } 
      ListNode *dummy = new ListNode(0); // Initialize the dummy node
      dummy->next=head;
      ListNode*prev=dummy;
      ListNode *curr=head;
      while(curr!=nullptr){
        if(curr->val==val){
            prev->next=curr->next;
            delete curr; // Use delete instead of free
            curr=prev->next;
        }
        else{
            prev=curr;
            curr=curr->next;
        }
      } 
      return dummy->next;
    }
};
