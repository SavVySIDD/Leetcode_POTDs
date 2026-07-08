class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1;  // base case for sum == k

        int sum = 0, count = 0;
        for (int num : nums) {
            sum += num;

            if (prefixSumCount.find(sum - k) != prefixSumCount.end()) {
                count += prefixSumCount[sum - k];
            }

            prefixSumCount[sum]++;
        }

        return count;
    }
};