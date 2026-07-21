class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n =nums.size();
        int left =0;
        int count0=0, count1=0;
        int res =INT_MIN;
        for(int right =0;right<n;right++){
            if(nums[right]==0) count0++;
            else count1++;
            if(right-left+1 > count1+k){
                while(nums[left]!=0){
                    left++;
                    count1--;
                }
                count0--;
                left++;
            }
            res = max(res,right-left+1);
        }
        return res;
    }
};