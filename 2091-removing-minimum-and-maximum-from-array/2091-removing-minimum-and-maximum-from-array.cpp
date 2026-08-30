class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minInd, maxInd;
        int mini = INT_MAX, maxi = INT_MIN;
        int n = nums.size();
        if(n==1) return n;
        for(int i=0;i<n;i++){
            if(nums[i]>maxi){
                maxi = nums[i];
                maxInd = i;
            }
            if(nums[i]<mini){
                mini = nums[i];
                minInd = i;
            }
        }
        int bothLeft        = max(minInd,maxInd)+1;
        int bothRight       = max(n-minInd, n-maxInd);
        int minLeftmaxRight = minInd+1+n-maxInd;
        int maxLeftminRight = maxInd+1+n-minInd;
        return min({bothLeft,bothRight,minLeftmaxRight,maxLeftminRight});
    }
};