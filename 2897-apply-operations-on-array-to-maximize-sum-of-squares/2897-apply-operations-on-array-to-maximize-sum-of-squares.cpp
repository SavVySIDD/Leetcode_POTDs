class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int bitCounts[31] = {0};
        for (int num : nums) {
            for (int i = 0; i <= 30; ++i) {
                if ((1 << i) & num) {
                    bitCounts[i]++;
                }
            }
        }

        long long totalSum = 0;
        long long MOD = 1e9 + 7;

        for (int j = 0; j < k; ++j) {
            long long currentNum = 0;
            for (int i = 30; i >= 0; --i) {
                if (bitCounts[i] > 0) {
                    currentNum |= (1LL << i);
                    bitCounts[i]--;
                }
            }
            totalSum = (totalSum + (currentNum * currentNum) % MOD) % MOD;
        }

        return totalSum;
    }
};