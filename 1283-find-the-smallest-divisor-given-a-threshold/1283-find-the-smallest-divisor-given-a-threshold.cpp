class Solution {
    long long check(vector<int>&nums,int divisor){
        long long res = 0;
        for(auto&it:nums){
            if(it%divisor!=0){ //not a multiple of the divisor
                res += (it+divisor)/divisor;
            }
            else res += it/divisor;
        }
        return res;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(begin(nums),end(nums));
        int res =0;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(check(nums,mid)<=threshold){
                res = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return res;
    }
};