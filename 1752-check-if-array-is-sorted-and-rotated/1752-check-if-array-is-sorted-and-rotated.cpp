class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        bool flag = true;
        int pos = 0;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]) {
                flag = false;
                pos = i+1;
            }
        }
        if(flag) return flag;
        int k = n-pos;
        k %=n; // rotated k times
        //right rotation steps
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
        flag = true;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]) {
                flag = false;
            }
        }
        return flag;
    }
};