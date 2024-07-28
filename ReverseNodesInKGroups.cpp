class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        stack<int>s;
        ListNode* temp=head;
        ListNode* temp2=head;
        int i;
        while(temp){
            for(i=1;i<=k;i++){
                if(temp==NULL) 
                    break;
                s.push(temp->val);
                temp=temp->next;
            }
            if(i!=k+1) break;
            for(i=1;i<=k;i++){
                temp2->val=s.top();
                s.pop();
                temp2=temp2->next;
            }
        }
        return head;
    }
};
