class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        if(m>n) return "";
        unordered_map<int,int>mp;
        for(auto&it:t) mp[it]++;
        int left = 0;
        int right = 0;
        int count =0;
        int sInd =-1;
        int mini =INT_MAX;
        while(right<n){
            if(mp[s[right]]>0) count++;
            mp[s[right]]--;
            while(count == m){
                if(right-left+1 < mini){
                    mini =right-left+1;
                    sInd = left;
                }
                mp[s[left]]++;
                if(mp[s[left]]>0) count-=1;
                left++;
            }
            right++;
        }
        return sInd==-1?"":s.substr(sInd,mini);
    }
};