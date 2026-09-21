class Solution {
public:
    int countChars(string s, int k){
        if(k<0) return 0;
        int n= s.size();
        int count =0;
        unordered_map<char,int> mp;
        int left=0;
        for(int right =0;right<n;right++){
            mp[s[right]]++;
            if(mp.size()>k){
                while(mp.size()>k){
                mp[s[left]]--;
                if(mp[s[left]]==0) mp.erase(s[left]);
                left++;
                }
            }
            count+= right-left+1;
        }
        return count;
    }

    int numberOfSubstrings(string s) {
        return countChars(s,3)- countChars(s,2);
    }
};