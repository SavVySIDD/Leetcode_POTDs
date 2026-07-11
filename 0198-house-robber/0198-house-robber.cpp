class Solution {
    // vector<int>dp{vector<int>(101,-1)};
    // int solve(vector<int>&nums,int ind){
    //     if(ind<0) return 0;
    //     if(dp[ind]!=-1) return dp[ind];
    //     int take = solve(nums,ind-2) + nums[ind];
    //     int notTake = solve(nums,ind-1);
    //     return dp[ind] = max(take,notTake);
    // }
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        // return solve(nums,nums.size()-1);
        int prev = nums[0];
        int prev2 = 0;
        for(int i=1;i<n;i++){
            int take = nums[i];
            if(i>1) take+= prev2;
            int notTake = prev;
            int curr = max(take,notTake);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};