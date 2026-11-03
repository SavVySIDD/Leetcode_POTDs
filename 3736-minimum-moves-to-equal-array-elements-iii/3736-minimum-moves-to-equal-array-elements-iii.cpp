class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int target = nums[n-1];
        int res = 0;
        for(int i=0;i<n-1;i++) res+= abs(nums[i]-target);
        return res;
    }
};