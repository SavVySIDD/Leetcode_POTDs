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
    ListNode* swapNodes(ListNode* head, int k) {
        int sz = 0;
        ListNode*temp = head;
        while(temp){
            temp = temp->next;
            sz++;
        }
        int first = k, last = sz-k+1;
        ListNode* First, *Last;
        temp = head;
        while(temp && first>1){
            temp = temp->next;
            first--;
        }
        First = temp;
        temp = head;

        while(temp && last>1){
            temp = temp->next;
            last--;
        }
        Last = temp;
        swap(First->val, Last->val);
        return head;
    }
};