class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        if(m>n) return "";
        unordered_map<char,int> mp;
        for(char c:t){
            mp[c]++;
        }
        int left=0,right=0,count=0;
        int minLen = INT_MAX, sInd=-1;
        while(right<n){
            if(mp[s[right]]>0) count+=1;
            mp[s[right]]--;
            while(count==m){
                if(right-left+1 < minLen){
                    minLen = right-left+1;
                    sInd = left;
                }
                mp[s[left]]++;
                if(mp[s[left]]>0) count-=1;
                left++;
            }
            right++;
        }
        return sInd == -1? "" : s.substr(sInd, minLen);
    }
};