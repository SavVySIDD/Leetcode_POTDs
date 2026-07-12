class Solution {
public:
    int candy(vector<int>& ratings) {
           // Initialize each child with 1 candy
        int n = ratings.size();
        vector<int> candies(n, 1);
        // Traverse from left to right
        for (int i = 1; i < n; ++i) {
            // If current rating is higher than previous, give more candies
            if (ratings[i] > ratings[i - 1])
                candies[i] = candies[i - 1] + 1;
        }
        // Traverse from right to left
        for (int i = n - 2; i >= 0; --i) {
            // If current rating is higher than next, adjust candy count
            if (ratings[i] > ratings[i + 1])
                candies[i] = max(candies[i], candies[i + 1] + 1);
        }
        return accumulate(candies.begin(), candies.end(), 0);
    }
};