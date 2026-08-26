class Solution {
    bool isLexicographicallySmall(string& s,int left,int sIdx){
        int tind1 = sIdx, tind2 = left;
        while(s[tind1]==s[tind2]){
            tind1++;
            tind2++;
        }
        if(s[tind1]>s[tind2]) return true;
        return false;
    }
public:
    string shortestBeautifulSubstring(string s, int k) {
        int left  = 0;
        int count = 0;
        int n     = s.size();
        int mini  = INT_MAX;
        int sIdx  = -1;
        for(int right=0;right<n;right++){
            if(s[right]-'0' == 1) count++;
            while(count == k){
                if(right-left+1 < mini){
                    mini = right-left+1;
                    sIdx = left;
                }else if(right-left+1 == mini && isLexicographicallySmall(s,left,sIdx)){
                    sIdx = left;
                }
                if(s[left]-'0' == 1) count--;
                left++;
            }
        }
        return sIdx==-1?"":s.substr(sIdx,mini);
    }
};