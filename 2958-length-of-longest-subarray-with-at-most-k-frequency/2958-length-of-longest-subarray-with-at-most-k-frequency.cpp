class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        int left = 0;
        int res = 0;
        for(int right =0;right<n;right++){
            mp[nums[right]]++;
            if(mp[nums[right]]>k){
                while(nums[left]!=nums[right]){
                    mp[nums[left]]--;
                    if(mp[nums[left]]==0) mp.erase(nums[left]);
                    left++;
                }
                mp[nums[left]]--;
                left++;
            }
            res = max(res, right-left+1);
        }
        return res;
    }
};