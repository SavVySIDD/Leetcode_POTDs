class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int res = INT_MIN;
        for(int right =0;right<n;right++){
            int curr = nums[right];
            if(curr==0) k--;
            if(k<0){
                while(nums[left]!=0){
                    left++;
                }
                left++;
                k++;
            }
            res= max(res,right-left+1);
        }
        return res;
    }
};