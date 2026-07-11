class Solution {
    vector<int>dp{vector<int>(101,-1)};
    int solve(vector<int>&nums,int ind){
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int take = solve(nums,ind-2) + nums[ind];
        int notTake = solve(nums,ind-1);
        return dp[ind] = max(take,notTake);
    }
public:
    int rob(vector<int>& nums) {
        return solve(nums,nums.size()-1);
    }
};