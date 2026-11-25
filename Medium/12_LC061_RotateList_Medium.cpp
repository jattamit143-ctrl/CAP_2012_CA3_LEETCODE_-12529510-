class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        
        // 1. Find list length and locate the current tail
        ListNode* tail = head;
        int length = 1;
        while (tail->next != nullptr) {
            tail = tail->next;
            length++;
        }
        
        // 2. Normalize k; if multiple of length, no rotation is needed
        k %= length;
        if (k == 0) return head;
        
        // 3. Form a circle and walk (length - k) steps to the new tail
        tail->next = head;
        int stepsToNewTail = length - k;
        ListNode* newTail = tail;
        while (stepsToNewTail--) {
            newTail = newTail->next;
        }
        
        // 4. Break the circle and return the new head
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        
        return newHead;
    }
};
