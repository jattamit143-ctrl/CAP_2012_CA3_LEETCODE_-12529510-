class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        
        // 1. Move prev to the node immediately before position 'left'
        for (int i = 0; i < left - 1; i++) {
            prev = prev->next;
        }
        
        // 2. Reverse the sublist from left to right via head insertion
        ListNode* curr = prev->next;
        for (int i = 0; i < right - left; i++) {
            ListNode* nextNode = curr->next;
            curr->next = nextNode->next;
            nextNode->next = prev->next;
            prev->next = nextNode;
        }
        
        return dummy.next;
    }
};
