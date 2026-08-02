class Solution {
    vector<vector<int>>dp;
    int solve(vector<int>& nums,int start, int end){
        int n = nums.size();
        if(start > end) return 0;
        if(start == end) return nums[start];
        if(dp[start][end]!=-1) return dp[start][end];
        // Now here we are taking minimum because both of the players are playing this game, so player 2 will also take the maximum possible which will leave us player 1 with the minimum of the possible scenarios
        int takeFront = nums[start] + min(solve(nums,start+1,end-1),solve(nums,start+2,end));
        int takeBack = nums[end] + min(solve(nums,start,end-2),solve(nums,start+1,end-1));
        return dp[start][end] = max(takeFront,takeBack);
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        int total = accumulate(begin(nums),end(nums),0);
        int n = nums.size();
        dp.resize(n,vector<int>(n,-1));
        int player1 = solve(nums,0,n-1);
        int player2 = total - player1;
        return player1>=player2;
    }
};