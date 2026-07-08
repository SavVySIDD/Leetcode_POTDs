class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int vote =0;
        for(auto it:nums){
            if(vote == 0){
                candidate = it;
            }
            if(candidate == it){
                vote++;
            }
            else vote--;
        }
        return candidate;
    }
};