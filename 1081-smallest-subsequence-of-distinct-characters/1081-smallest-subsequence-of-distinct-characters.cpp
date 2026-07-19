class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char,int>mp;
        for(auto& it:s){
            mp[it]++;
        } // mapping of all the occurences

        vector<bool> seen(26,false); //seen in the result string

        string res="";
        for(auto& it:s){
            mp[it]--;
            if(seen[it-'a']) continue;
            while(!res.empty() && res.back()>it && mp[res.back()]>0){
                seen[res.back()-'a'] = false;
                res.pop_back();
            }
            res.push_back(it);
            seen[it-'a'] = true;
        }
        return res;
    }
};