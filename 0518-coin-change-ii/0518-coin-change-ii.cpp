class Solution {
    vector<vector<int>>dp;
    int solve(int amount, vector<int>&coins, int ind){
        if(amount ==0) return 1;
        else if(ind>=coins.size()) return 0;
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int take = 0;
        if(coins[ind]<=amount){
            take = solve(amount-coins[ind],coins,ind);
        }
        int notTake = solve(amount,coins,ind+1);
        return dp[ind][amount]= take+notTake;
    }
public:
    int change(int amount, vector<int>& coins) {
        dp.assign(coins.size(),vector<int>(amount+1,-1));
        sort(begin(coins),end(coins),greater<int>());
        return solve(amount,coins,0);
    }
};