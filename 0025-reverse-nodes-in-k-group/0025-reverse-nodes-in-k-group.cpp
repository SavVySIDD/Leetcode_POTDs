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
    ListNode* getKthNode(ListNode*head, int k){
        ListNode* temp = head;
        int i=1;
        while(temp && i<k){
            temp = temp->next;
            i++;
        }
        return temp;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // ListNode* dummy = new ListNode(0);
        // dummy->next = head;
        ListNode*temp = head;
        ListNode*nextNode = nullptr, *prevNode = nullptr;
        while(temp){
            ListNode* kthNode = getKthNode(temp,k);
            if(!kthNode){
                if(prevNode) prevNode->next = temp;
                break;
            }
            nextNode = kthNode->next;
            kthNode->next = nullptr;
            reverse(temp);
            if(head == temp){//1 traversal
                head = kthNode;
            }else{
                prevNode->next = kthNode;
            }
            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};