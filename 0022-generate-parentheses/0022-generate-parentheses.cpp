class Solution {
    vector<string>res;
    void solve(int n,int open,int close,string curr){
        if(curr.size()==2*n){
            res.push_back(curr);
            return;
        }
        if(open<n)      solve(n,open+1,close,curr+'(');
        if(close<open)  solve(n,open,close+1,curr+')');
        return;
    }
public:
    vector<string> generateParenthesis(int n) {
        solve(n,0,0,"");
        return res;
    }
};