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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr = new ListNode();
        ListNode* res = curr;
        bool carry=false;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        while(temp1!=NULL && temp2!=NULL){
            int sum = temp1->val + temp2->val;
            if(carry){
                sum++;
                carry =false;
            }
            if(sum>9){
                carry = true;
                sum%=10;
            }
            temp1=temp1->next;
            temp2=temp2->next;
            res->next = new ListNode(sum);
            res=res->next;
        }
        while(temp2!=NULL){
            int sum = temp2->val + (carry ? 1 : 0); 
            carry = sum > 9;
            sum %= 10;      

            res->next = new ListNode(sum);
            res = res->next;
            temp2 = temp2->next;
        }
        while(temp1!=NULL){
            int sum = temp1->val + (carry ? 1 : 0); 
            carry = sum > 9;
            sum %= 10;       

            res->next = new ListNode(sum);
            res = res->next;
            temp1 = temp1->next;
        }
        if (carry) {
            res->next = new ListNode(1);
        }
        return curr->next;
    }
};