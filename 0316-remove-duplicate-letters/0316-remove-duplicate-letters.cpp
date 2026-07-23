class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
        string result;
        vector<bool> taken(26, false); //O(1) space
        vector<int> lastIndex(26); //O(1) space

        for(int i = 0; i < n; i++) { // We got the last index from this
            char ch = s[i]; 
            lastIndex[ch-'a'] = i;
        }
        
        for(int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            if(taken[idx] == true) continue;
            while(result.length() > 0 && s[i] < result.back() 
            && lastIndex[result.back() - 'a'] > i)  // Here we check if the already pushed character is larger than this new character and if yes and it appears later we pop it and then it will later be pushed when coming again.
            {
                taken[result.back() - 'a'] = false;
                result.pop_back();
            }
            result.push_back(s[i]);
            taken[idx] = true;
        }
        
        return result;
    }
};