class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int minPrice = INT_MAX;

        // dp[b] = maximum copies from first purchases
        // using a budget of at most b.
        vector<int> dp(budget + 1, 0);

        for (int i = 0; i < n; i++) {
            int factor = items[i][0];
            int price = items[i][1];

            minPrice = min(minPrice, price);

            // Count the purchased copy and all free copies.
            int gain = 0;
            for (int j = 0; j < n; j++) {
                if (items[j][0] % factor == 0) {
                    gain++;
                }
            }

            // 0/1 knapsack: buy the first copy of this type at most once.
            for (int b = budget; b >= price; b--) {
                dp[b] = max(dp[b], dp[b - price] + gain);
            }
        }

        int answer = 0;

        // Spend b on first purchases and the remaining budget
        // on copies of the cheapest item.
        for (int b = 0; b <= budget; b++) {
            int extraCopies = (budget - b) / minPrice;
            answer = max(answer, dp[b] + extraCopies);
        }

        return answer;
    }
};