class Solution {
    int findFirst(vector<int>&nums,int target){
        int low = 0, high = nums.size()-1;
        int res = -1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]==target){ 
                res = mid;
                high = mid-1;
            }
            else if(nums[mid]>target){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return res;
    }
    int findLast(vector<int>&nums,int target){
        int low = 0, high = nums.size()-1;
        int res = -1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]==target){ 
                res = mid;
                low = mid+1;
            }
            else if(nums[mid]<target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return res;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        //first occurence
        int f = findFirst(nums,target);
        int l = findLast(nums,target);
        return {f,l};
    }
};