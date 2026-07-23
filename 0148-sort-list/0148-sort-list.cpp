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
    ListNode* findMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next; //to get the firs middle in the even case

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* res = new ListNode(-1);
        ListNode* temp = res;

        while (left && right) {
            if (left->val <= right->val) {
                temp->next = left;
                left = left->next;
            } else {
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }

        if (left)
            temp->next = left;
        else
            temp->next = right;

        return res->next;
    }

    ListNode* mergeSort(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* mid = findMid(head);
        ListNode* right = mid->next;
        mid->next = nullptr; // breaking the list

        ListNode* left = mergeSort(head);
        right = mergeSort(right);

        return merge(left, right);
    }
public:
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};