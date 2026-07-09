class Solution {
public:
    int calcK(vector<int>& nums, int k){
        if(k<0) return 0;
        int n = nums.size();
        int left=0,count=0;
        unordered_map<int,int> mp;
        for(int right=0;right<n;right++){
            mp[nums[right]]++;
            if(mp.size()>k){
                while(mp.size()>k){
                    mp[nums[left]]--;
                    if(mp[nums[left]]==0) mp.erase(nums[left]);
                    left++;
                }
            }
            count += right-left+1;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return calcK(nums,k)- calcK(nums,k-1);
    }
};