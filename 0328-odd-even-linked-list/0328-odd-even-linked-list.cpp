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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* resOdd = new ListNode(-1);
        ListNode* temp1 = resOdd;
        ListNode* resEven = new ListNode(-1);
        ListNode* temp2 = resEven;
        int i=1;
        while(head!=NULL){
            if(i%2==0){
                resEven->next = new ListNode(head->val);
                resEven= resEven->next;
            }
            else{
                resOdd->next = new ListNode(head->val);
                resOdd= resOdd->next;
            }
            head=head->next; i++;
        }
        if(resEven) resOdd->next = temp2->next;
        
        return temp1->next;
    }
};