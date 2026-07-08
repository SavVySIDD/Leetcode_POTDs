class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left =0;
        int n=nums.size();
        int count=0;
        for(int right =0; right < n; right++){
            int x = nums[right];
            if(x==0 && right >= left){
                left = right+1;
            }
            count = max(count,right-left+1);
        }
        return count;
    }
};