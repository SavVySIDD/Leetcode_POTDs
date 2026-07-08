class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = INT_MIN;
        int n = prices.size();
        int l = 0;
        for(int r=0;r<n;r++){
            int buy = prices[l];
            int sell = prices[r];
            if(sell<buy){
                l =r;
                sell = buy;
            }
            res = max(res,sell-buy);
        }
        return res;
    }
};