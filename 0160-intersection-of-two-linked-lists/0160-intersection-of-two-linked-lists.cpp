/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1,*temp2;
        temp1=headA;
        temp2=headB;
        int n=0,m=0;
        while(temp1!=NULL){
            temp1 = temp1->next;
            n++;
        }
        while(temp2!=NULL){
            temp2 = temp2->next;
            m++;
        }
        int diff = abs(n-m);
        int x=0;
        temp1=headA;
        temp2=headB;
        
        if(n>m){
            while(x<diff){
                temp1=temp1->next;
                x++;
            }
        }
        else{
            while(x<diff){
                temp2=temp2->next;
                x++;
            }
        }
        while(temp1 != temp2 ){ //As they share a common Node in memory
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return temp2;
    }
};