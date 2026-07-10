class Solution {
    int solve(vector<int>&nums,int k){
        unordered_map<int,int>mp;
        int left = 0;
        int count = 0;
        for(int right = 0; right<nums.size(); right++){
            int curr = nums[right];
            mp[curr]++;
            while(mp.size()>k){
                mp[nums[left]]--;
                if(mp[nums[left]]==0) mp.erase(nums[left]);
                left++;
            }
            count+=right-left+1;
        }
        return count;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k) - solve(nums,k-1);
    }
};