class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left =0;
        int n=nums.size();
        int count=0;
        for(int right =0; right < n; right++){
            if (nums[right] == 0) {
                k--; // Use one flip
            }

            // If we used more than k flips, shrink from the left
            while (k < 0) {
                if (nums[left] == 0) {
                    k++; // Reclaim a flip
                }
                left++;
            }

            count = max(count, right - left + 1);
        }
        return count;
    }
};