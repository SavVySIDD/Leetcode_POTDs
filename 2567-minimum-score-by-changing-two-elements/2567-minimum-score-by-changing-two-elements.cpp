class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        return min({
            nums[n - 3] - nums[0],     // Change the two largest elements
            nums[n - 2] - nums[1],     // Change the smallest and largest
            nums[n - 1] - nums[2]      // Change the two smallest elements
        });
    }
};