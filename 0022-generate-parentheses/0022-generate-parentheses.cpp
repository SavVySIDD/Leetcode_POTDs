class Solution {
    vector<string>res;
    void solve(int n,int open,int close,string& curr){
        if(curr.size()==2*n){
            res.push_back(curr);
            return;
        }
        if(open<n){      
            curr.push_back('(');
            solve(n,open+1,close,curr);
            curr.pop_back();
        }
        if(close<open){
            curr.push_back(')');
            solve(n,open,close+1,curr);
            curr.pop_back();
        }  
        return;
    }
public:
    vector<string> generateParenthesis(int n) {
        string curr;
        solve(n,0,0,curr);
        return res;
    }
};