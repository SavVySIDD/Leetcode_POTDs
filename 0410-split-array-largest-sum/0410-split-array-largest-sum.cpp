class Solution {
    int check(vector<int>&nums, int req){
        int count =1;
        int sum =0;
        for(auto&it:nums){
            if(sum + it>req){
                count++;
                sum=it;
            }
            else{
                sum+=it;
            }
        }
        return count;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(begin(nums),end(nums));
        int high = accumulate(begin(nums),end(nums),0);
        int ans = -1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(check(nums,mid)<=k){
                ans = mid;
                high =mid-1;
            }
            else{low = mid+1;}
        }
        return ans;
    }
};