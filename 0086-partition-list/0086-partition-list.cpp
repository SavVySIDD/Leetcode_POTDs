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
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(-1);
        ListNode* sTail = small;
        ListNode* large = new ListNode(-1);
        ListNode* lTail = large;

        while(head){
            if(head->val <x){
                sTail->next = new ListNode(head->val);
                sTail = sTail->next;
            }else{
                lTail->next = new ListNode(head->val);
                lTail = lTail->next;
            }
            head = head->next;
        }
        sTail->next = large->next;
        return small->next;
    }
};