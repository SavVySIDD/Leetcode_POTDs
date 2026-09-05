class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>nse(n);
        nse[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            nse[i] = min(nse[i+1],nums[i]);
        }
        int pge = INT_MIN;
        for(int i=0;i<n;i++){
            pge = max(pge,nums[i]);
            int instability = pge-nse[i];
            if(instability <= k) return i;
        }
        return -1;
    }
};