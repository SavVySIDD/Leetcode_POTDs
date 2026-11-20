class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        // dp[v] = longest consecutive sequence ending at v
        int maxValue = nums.back();
        vector<int> dp(maxValue + 2, 0);

        int answer = 0;

        for (int x : nums) {
            // Increase x to x + 1.
            dp[x + 1] = max(dp[x + 1], dp[x] + 1);

            // Keep x unchanged.
            dp[x] = max(dp[x], dp[x - 1] + 1);

            answer = max({answer, dp[x], dp[x + 1]});
        }

        return answer;
    }
};