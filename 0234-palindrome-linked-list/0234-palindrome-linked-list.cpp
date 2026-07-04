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
    bool isPalindrome(ListNode* head) {
        ListNode* temp1 = head;
        int n=0;
        vector<int> res;
        while(temp1!=NULL){
            res.push_back(temp1->val);
            temp1 = temp1->next;
            n++;
        }
        vector<int> temp = res;
        reverse(temp.begin(),temp.end());
        if(temp==res) return true;
        return false;
    }
};