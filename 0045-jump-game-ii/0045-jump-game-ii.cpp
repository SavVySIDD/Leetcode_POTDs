class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int farthest =0;
        int jumps =0;
        int currend =0;
        for(int i=0;i<n-1;i++){ // we are taking the benefit of the point that we are sure that we can reach to the end so we just calculate the farthes we can go with every jump and only add when we reach to that index
            farthest = max(farthest,nums[i]+i);
            if(farthest >= n-1) return jumps+1;
            if(i==currend){
                jumps++;
                currend = farthest;
            }
        }
        return jumps;
    }
};