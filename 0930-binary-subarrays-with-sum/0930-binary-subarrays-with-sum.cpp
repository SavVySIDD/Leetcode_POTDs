class Solution {
public:
    int calcGoal(vector<int>& nums, int goal){
        if(goal<0) return 0;
        int n = nums.size();
        int left=0,count=0;
        int sum =0;
        for(int right=0;right<n;right++){
            sum+= nums[right];
            if(sum>goal){
                while(sum>goal){
                    sum -= nums[left];
                    left++;
                }
            }
            count += right-left+1; 
            // calculating sum <= goal and so each no. alone also is a subset which is lesser and equal to goal, that is why we are adding the numbers in between to count
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return calcGoal(nums,goal)- calcGoal(nums,goal-1);
        //Basically we calculated all subarrays containing sum<=goal and sum<=goal-1 and then subtracted that.
    }
};