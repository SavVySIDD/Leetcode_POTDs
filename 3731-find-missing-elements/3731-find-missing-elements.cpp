class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini = *min_element(nums.begin(),nums.end());
        int maxi = *max_element(nums.begin(),nums.end());

        unordered_set<int> st(nums.begin(),nums.end());
        vector<int>res;
        for(int i=mini;i<=maxi;i++) if(!st.count(i))res.push_back(i);
        return res;
    }
};