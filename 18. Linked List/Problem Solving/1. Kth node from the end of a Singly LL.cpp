//19 leetcode
ListNode* removeNthFromEnd(ListNode* head, int k) {
        if (head==NULL)
            return head;
        if (head->next==NULL)
            return NULL;
        ListNode* first = head;
        ListNode* second = head;
        int i;
        for(i=0;i<n+1 && first!=NULL;i++){
            first = first->next;
        }
        if (i==n && first==NULL)
            return head->next;
        while (first!=NULL){
            second = second->next;
            first = first->next;
        }
        second->next = second->next->next;    
        return head;
    }