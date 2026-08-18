class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(auto&it:nums){
            mp[it]++;
        }
        if(k==1){
            int maxi = INT_MIN;
            for(auto&it:nums){
                if(mp[it]==1){
                    maxi = max(maxi,it);
                }
            }
            return maxi==INT_MIN?-1:maxi;
        }
        if(k==n){
            return *max_element(begin(nums),end(nums));
        }
        int firstEle = nums[0];
        int lastEle  = nums[n-1];
        if(mp[firstEle]==1 && mp[lastEle]==1) return firstEle>lastEle ? firstEle : lastEle;
        if(mp[firstEle]==1) return firstEle;
        if(mp[lastEle]==1) return lastEle;
        return -1;
    }
};