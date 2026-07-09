class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int left =0, maxF=0;
        int count =0;
        vector <int> hash(26,0);
        for(int right=0; right < n; right++){
            hash[s[right]-'A']++;
            maxF = max(maxF, hash[s[right]-'A']);
            if((right-left+1)-maxF > k){
                hash[s[left]-'A']--; 
                maxF=0;
                for(int i=0;i<26;i++) maxF = max(maxF, hash[i]);
                left++;
            }
            count = max(count, right-left+1);
        }
        return count;
    }
};