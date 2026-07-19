class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int left =0,maxF=INT_MIN;
        // unordered_map<char,int>mp;
        vector<int>freq(26,0);
        int res = INT_MIN;
        for(int right =0;right<n;right++){
            char curr = s[right];
            freq[curr-'A']++;
            maxF = max(maxF,freq[curr-'A']);
            if(right-left+1>maxF+k){
                freq[s[left]-'A']--;
                maxF=0;
                for(auto&it:freq) maxF = max(maxF,it);
                left++;
            }
            res = max(res,right-left+1);
        }
        return res;
    }
};