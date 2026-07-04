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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;
        int sz =0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            sz++;
        }
        if (n == sz) { // I was missing this edge case again and again
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        int k = sz-n+1; // from first
        temp = head;
        ListNode* curr=NULL;
        for(int i=1;i<k;i++){
            curr = temp;
            temp = temp->next;
        }
        curr->next = temp->next;
        delete temp;
        return head;
    }
};