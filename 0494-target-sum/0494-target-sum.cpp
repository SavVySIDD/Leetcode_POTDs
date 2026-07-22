class Solution {
    vector<vector<int>>dp;
    int total;
    int solve(vector<int>&nums, int target, int ind, int curr){
        if(ind>=nums.size() && target ==curr) return 1;
        if(ind>=nums.size()) return 0;
        if(dp[ind][curr+total]!=-1) return dp[ind][curr+total];
        int pos = solve(nums,target,ind+1,curr-nums[ind]);
        int neg = solve(nums,target,ind+1,curr+nums[ind]);
        return dp[ind][curr+total]= pos+neg;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        total = accumulate(nums.begin(), nums.end(), 0);
        dp.resize(nums.size(),vector<int>(2*total+1,-1));
        return solve(nums,target,0,0);
    }
};