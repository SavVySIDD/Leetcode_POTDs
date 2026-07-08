class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count0=0,count1=0,count2=0;
        for(int i:nums){
            if(i==0) count0++;
            else if(i==1) count1++;
            else count2++;
        }
        nums.clear();
        while(count0--){
            nums.push_back(0);
        }
        while(count1--){
            nums.push_back(1);
        }
        while(count2--){
            nums.push_back(2);
        }
    }
};