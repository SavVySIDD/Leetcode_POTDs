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
    ListNode* myHead;
public:
    Solution(ListNode* head) {
        myHead = head;
    }
    
    int getRandom() {
        int sz =0;
        ListNode*temp=myHead;
        vector<int>v;
        while(temp){
            v.push_back(temp->val);
            temp=temp->next;
            sz++;
        }
        int r = rand()%sz;
        return v[r];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */