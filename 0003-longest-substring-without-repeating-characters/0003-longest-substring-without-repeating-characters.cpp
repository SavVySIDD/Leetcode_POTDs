class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int left = 0;
        int max_count=0;
        int n = s.size();
        for(int right=0;right<n;right++){
            char c = s[right];
            if(mp.count(c)&& mp[c]>=left){
                left = mp[c]+1;
            }
            mp[c]=right;
            max_count = max(max_count,right-left+1);
        }
        return max_count;
    }
};