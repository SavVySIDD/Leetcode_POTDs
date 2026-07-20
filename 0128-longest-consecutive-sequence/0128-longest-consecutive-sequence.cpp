class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        unordered_set<int>st(nums.begin(),nums.end());
        int cnt = 1;
        int res = INT_MIN;
        for(auto&it:st){
            if(!st.count(it-1)){
                int val = it;
                while(st.count(val+1)){
                    cnt++;
                    val++;
                }
                res = max(cnt,res);
                cnt=1;
            }
        }
        return res;
    }
};