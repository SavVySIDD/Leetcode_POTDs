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
    ListNode* getKth(ListNode* head, int k){
        ListNode* temp = head;
        for(int i=1;i<k;i++){
            temp = temp->next;
        }
        return temp;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) return head;
        ListNode* temp = head;

        int curr=1;
        while(temp->next != NULL){
            temp=temp->next;
            curr++;
        }
        k = k%curr;
        temp->next = head;
        ListNode* node = getKth(head,curr-k);
        head = node->next;
        node->next = NULL;
        
        return head;
    }
};