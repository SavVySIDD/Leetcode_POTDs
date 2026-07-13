class Solution {
    vector<vector<int>> dp;
    bool solve(vector<int>& nums, int n , int ind, int val){
        if(ind>n-1 || val<0) return false;
        if(val==0) return true;
        if(dp[ind][val]!=-1) return dp[ind][val];
        return dp[ind][val] = solve(nums,n,ind+1,val-nums[ind]) || solve(nums,n,ind+1,val);
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0) return false;
        dp.assign(n, vector<int>(sum / 2 + 1, -1));
        return solve(nums,n,0,sum/2);
    }
};