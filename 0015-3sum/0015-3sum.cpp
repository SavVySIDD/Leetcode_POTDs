class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>>res;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int k= nums[i]; //fixed the first number
            int x = i+1;
            int y = n-1;
            while(x<y){ //finding the other two using 2 pointer
                int n1 = nums[x];
                int n2 = nums[y];
                int sum = k + nums[x] + nums[y];
                if(sum==0){
                    res.push_back({k,n1,n2});
                    y--;
                    x++;
                    while(x<y && nums[x]==nums[x-1]) x++;
                    while(x<y && nums[y]==nums[y+1]) y--;
                }
                else if(sum<0) x++;
                else if(sum>0) y--;
            }
        }
        return res;
    }
};