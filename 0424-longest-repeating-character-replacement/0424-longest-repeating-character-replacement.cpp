class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int left =0,maxF=INT_MIN;
        unordered_map<char,int>mp;
        int res = INT_MIN;
        for(int right =0;right<n;right++){
            char curr = s[right];
            mp[curr]++;
            maxF = max(maxF,mp[curr]);
            if(right-left+1>maxF+k){
                mp[s[left]]--;
                maxF=0;
                for(auto&it:mp) maxF = max(maxF,it.second);
                left++;
            }
            res = max(res,right-left+1);
        }
        return res;
    }
};