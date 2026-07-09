class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(begin(nums),end(nums));
        int n = nums.size();
        vector<vector<int>> res;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int n1 = nums[i];
            for(int j=i+1;j<n;j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int n2 = nums[j];
                int x = j+1;
                int y = n-1;
                while(x<y){
                    long long sum = 1LL * n1+n2+nums[x]+nums[y];
                    if(sum == target){
                        res.push_back({n1,n2,nums[x],nums[y]});
                        x++;
                        y--;
                        while(x<y && nums[x]==nums[x-1]) x++;
                        while(x<y && nums[y]==nums[y+1]) y--; 
                    }
                    else if(sum<target) x++;
                    else y--;
                }
            }
        }
        return res;
    }
};