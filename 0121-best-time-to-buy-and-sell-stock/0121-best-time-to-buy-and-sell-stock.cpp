class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = INT_MIN;
        int n = prices.size();
        int buy = prices[0];
        for(int r=0;r<n;r++){
            int sell = prices[r];
            if(sell<buy){
                buy = sell;
            }
            res = max(res,sell-buy);
        }
        return res;
    }
};