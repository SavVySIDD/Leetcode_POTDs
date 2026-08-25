class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>st(begin(nums),end(nums));
        int x=1;
        while(true){
            int p = k*x;
            if(!st.count(p))return p;
            x++;
        }
        return -1;
    }
};