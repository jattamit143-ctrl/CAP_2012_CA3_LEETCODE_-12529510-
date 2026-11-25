class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        
        while (curr != nullptr && curr->next != nullptr) {
            if (curr->val == curr->next->val) {
                curr->next = curr->next->next; // Skip the duplicate node
            } else {
                curr = curr->next;             // Move to the next distinct value
            }
        }
        
        return head;
    }
};
