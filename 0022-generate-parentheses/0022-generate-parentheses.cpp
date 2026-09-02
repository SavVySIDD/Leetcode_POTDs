class Solution {
    void solve(int n, vector<string>&res,int open,int close,string curr){
        if(curr.size()==2*n){
            res.push_back(curr);
            return;
        }
        if(open<n)      solve(n,res,open+1,close,curr+'(');
        if(close<open)  solve(n,res,open,close+1,curr+')');
        return;
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        solve(n,res,0,0,"");
        return res;
    }
};