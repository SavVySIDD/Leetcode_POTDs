class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxJump = 0;
        for(int i =0 ;i<n; i++){
            int curr = nums[i];
            if(i>maxJump) return false;
            if(i+curr>=n) return true;
            maxJump = max(maxJump,curr+i);
        }
        return true;
    }
};