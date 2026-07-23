class Solution {

    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (!head || left == right)
            return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Reach node just before 'left'
        ListNode* leftPrev = dummy;
        for (int i = 1; i < left; i++)
            leftPrev = leftPrev->next;

        // First node of sublist
        ListNode* subHead = leftPrev->next;

        // Reach 'right' node
        ListNode* rightNode = subHead;
        for (int i = left; i < right; i++)
            rightNode = rightNode->next;

        // Store node after 'right'
        ListNode* rightNext = rightNode->next;

        // Detach the sublist
        rightNode->next = nullptr;

        // Reverse the detached sublist
        ListNode* newHead = reverse(subHead);

        // Reconnect
        leftPrev->next = newHead;
        subHead->next = rightNext;

        return dummy->next;
    }
};