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
    ListNode* merge2Lists(ListNode*l1, ListNode*l2){
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1->val<=l2->val){
            l1->next = merge2Lists(l1->next,l2);
            return l1;
        }
        else{
            l2->next = merge2Lists(l2->next,l1);
            return l2;
        }
        return NULL;
    }

    ListNode* splitAndMerge(int start, int end, vector<ListNode*>& lists){
        if(start>end) return nullptr;
        if(start == end) return lists[start];
        int mid = start + (end-start)/2;
        ListNode* l1 = splitAndMerge(start,mid,lists);
        ListNode* l2 = splitAndMerge(mid+1,end,lists);
        return merge2Lists(l2,l1);
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k==0) return nullptr;
        return splitAndMerge(0,k-1,lists);
    }
};