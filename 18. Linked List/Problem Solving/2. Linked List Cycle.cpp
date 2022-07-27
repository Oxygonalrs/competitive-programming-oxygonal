//141 Leetcode
bool hasCycle(ListNode *head) {
    if(head == NULL) return false;
    if(head->next == NULL) return false;
    ListNode* slow = head;
    ListNode* fast = head;
    slow = slow->next;
    fast = fast->next->next;
    while(slow && fast && fast->next)
    {
        if(slow == fast) return true;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return false;
}

//Again visit Leetcode to know another way to solve this problem