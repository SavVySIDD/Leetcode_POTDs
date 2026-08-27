class Solution {
    string res = "";
    bool solve(string& curr,vector<int>&hash,string& target, int ind, bool greater){
        if(ind == target.size()){
            if(greater){
                res = curr;
                return true;
            }
            return false;
        }
        for(char ch = 'a';ch<='z';ch++){
            if(hash[ch-'a']==0) continue;
            if(ch<target[ind] && !greater) continue;

            curr.push_back(ch);
            hash[ch-'a']--;
            bool isGreater = greater || ch > target[ind];
            if(solve(curr,hash,target,ind+1,isGreater)){
                return true; //Lexicographically First
            }
            curr.pop_back();
            hash[ch-'a']++;
        }
        return false;
    }
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int>hash(26,0);
        for(char& c:s){
            hash[c-'a']++;
        }
        string curr;
        solve(curr,hash,target,0,false);
        return res;
    }
};