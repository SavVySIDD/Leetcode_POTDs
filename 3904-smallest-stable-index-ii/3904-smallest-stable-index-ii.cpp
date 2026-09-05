class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>pge(n),nse(n);
        pge[0]=nums[0];
        nse[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            nse[i] = min(nse[i+1],nums[i]);
        }
        for(int i=0;i<n;i++){
            if(i!=0)pge[i] = max(pge[i-1],nums[i]);
            int instability = pge[i]-nse[i];
            if(instability <= k) return i;
        }
        return -1;
    }
};