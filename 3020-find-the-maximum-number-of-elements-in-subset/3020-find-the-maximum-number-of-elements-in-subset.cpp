class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        map<int,int>mp;
        for(auto&it:nums){
            mp[it]++;
        }
        int res = INT_MIN;
        if(mp.count(1)){
            int ones = mp[1];
            if(ones % 2 == 0) ones--;
            res = max(res, ones);
        }
        for(auto&[x,freq]:mp){
            if(x==1) continue;
            int cnt =0;
            long long curr = x;
              while (mp[curr] >= 2 && mp.count(curr * curr)) {
                cnt += 2;
                if(curr > maxi / curr) break;
                curr = curr * curr;
            }
            if(mp.count(curr)) cnt++;
            res = max(cnt,res);
        }
        return res;
    }
};