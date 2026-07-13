class Solution {
    vector<vector<int>>dp;
    int solve(vector<int>& coins, int amount, int ind){
        if(amount==0) return 0;
        if(ind>=coins.size()) return INT_MAX;
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int n = coins.size();
        int take = INT_MAX;

        if(coins[ind]<=amount){
            int res = solve(coins,amount-coins[ind],ind);
            if(res!=INT_MAX){
                take = 1+res;
            }
        }

        int notTake = solve(coins,amount,ind+1);
        return dp[ind][amount] =  min(take,notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        dp.assign(coins.size(),vector<int>(amount+1,-1));
        sort(begin(coins),end(coins),greater<int>());
        int res =  solve(coins,amount,0);
        return res==INT_MAX?-1:res;
    }
};