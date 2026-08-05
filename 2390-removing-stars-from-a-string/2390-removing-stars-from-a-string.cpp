class Solution {
public:
    string removeStars(string s) {
        string res = "";
        int n = s.size();
        for(char c : s){
            if(c == '*')
                res.pop_back();
            else
                res.push_back(c);
        }
        return res;
    }
};