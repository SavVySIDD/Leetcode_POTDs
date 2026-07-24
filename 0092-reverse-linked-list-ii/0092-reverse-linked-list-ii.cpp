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

public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next) return head;
        ListNode*temp = head;
        int k=1;
        ListNode*prev = nullptr;
        while(temp && k<left){ //get the left start of the ListNode
            prev = temp;
            temp = temp->next;
            k++;
        }
        ListNode* leftStart = temp;
        while(temp && k<right){
            temp = temp->next;
            k++;
        }
        ListNode* rightEnd = temp;
        ListNode* nextNode = rightEnd->next;
        rightEnd->next = nullptr;
        reverse(leftStart);
        if(left==1){ // head was also rotated
            head = rightEnd;
        }else{
            if(prev)prev->next = rightEnd;
        }
        leftStart->next = nextNode;
        return head;
    }
};