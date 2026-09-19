class Solution {
    void solve(vector<vector<int>>&res,vector<int>&nums,int ind,vector<int>&temp){
        res.push_back(temp);
        for(int i=ind;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            solve(res,nums,i+1,temp);
            temp.pop_back(); 
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>temp;
        sort(begin(nums),end(nums));
        solve(res,nums,0,temp);
        return res;
    }
};