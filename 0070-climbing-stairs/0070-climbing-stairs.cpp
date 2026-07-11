class Solution {
public:
    int climbStairs(int n) {
        // if(n<0) return 0;
        // if(n==0) return 1;
        // if(dp[n]!=-1) return dp[n];
        // return dp[n] = climbStairs(n-1)+climbStairs(n-2);
        int prev1=1;
        int prev2=1;
        for(int i=2;i<=n;i++){
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }

};