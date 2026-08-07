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
        ListNode*prev = nullptr;
        while(temp){
            prev = temp;
            temp = temp->next;
            sz++;
        }

        ListNode* First = head, *Last =head;
        temp = head;
        while(temp && k>1){
            temp = temp->next;
            k--;
        }
        First = temp;
        while(temp->next){
            Last = Last->next;
            temp = temp->next;
        }

        swap(First->val, Last->val);
        return head;
    }
};