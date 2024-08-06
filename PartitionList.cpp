class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next)
            return head;

        ListNode* greater = new ListNode(-1);
        ListNode* smaller = new ListNode(-1);

        ListNode* dumg = greater;
        ListNode* dums = smaller;
        
        while(head){
            if(head->val >= x){
                dumg->next = head;
                dumg = head;
            }
            else{
                dums->next = head;
                dums = head;
            }

            head = head->next;
        }
        dumg->next = NULL;
        dums->next = greater->next;
        
        return smaller->next;
    }
};
