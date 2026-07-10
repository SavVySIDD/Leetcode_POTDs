class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        //first occurence
        int f=-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]==target){
                f=mid;
                high = mid-1;
            }
            else if(nums[mid]>target){
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }
        int l=-1;
        low = 0; high = n-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]==target){
                l=mid;
                low = mid+1;
            }
            else if(nums[mid]<target){
                low = mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return {f,l};
    }
};