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
    ListNode* reverse(ListNode* l){
        ListNode* prev = nullptr;
        while(l){
            ListNode* nxt = l->next;
            l->next = prev;
            prev = l;
            l = nxt;
        }
        return prev;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = reverse(l1);
        ListNode* t2 = reverse(l2);
        bool carry = false;
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
        while(t1 && t2){
            int sum = t1->val + t2->val;
            if(carry){
                sum++;
            }
            carry = false;
            if(sum>9){
                carry = true;
            }
            tail->next = new ListNode(sum%10);
            tail = tail->next;
            t1 = t1->next;
            t2 = t2->next;
        }

        while(t1){
            int sum = t1->val;
            if(carry){
                sum++;
            }
            carry = false;
            if(sum>9){
                carry = true;
            }
            tail->next = new ListNode(sum%10);
            tail = tail->next;
            t1 = t1->next;
        }
        while(t2){
            int sum = t2->val;
            if(carry){
                sum++;
            }
            carry = false;
            if(sum>9){
                carry = true;
            }
            tail->next = new ListNode(sum%10);
            tail = tail->next;
            t2 = t2->next;
        }
        if(carry){
            tail->next = new ListNode(1);
            tail = tail->next;
        }
        dummy = reverse(dummy->next);
        return dummy;
    }
};