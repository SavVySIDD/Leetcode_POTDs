class Solution {
    vector<vector<int>>dp;
    int solve(vector<int>& nums,int start, int end){
        if(start == end) return nums[start];
        if(dp[start][end]!=-1) return dp[start][end];
        int takeFront = nums[start] - solve(nums,start+1,end);
        int takeBack  = nums[end]   - solve(nums,start,end-1);
        return dp[start][end] =  max(takeFront,takeBack);
    }
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        dp.resize(n,vector<int>(n,-1));
        int diff = solve(piles,0,piles.size()-1);
        return diff>0?true:false;
    }
};