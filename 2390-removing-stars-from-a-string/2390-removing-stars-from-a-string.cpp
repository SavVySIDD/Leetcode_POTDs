class Solution {
public:
    string removeStars(string s) {
        string res = "";
        int n = s.size();
        stack<char>st;
        for(int i=n-1;i>=0;i--){
            st.push(s[i]);
        }
        while(!st.empty()){
            char c = st.top();
            if(c=='*'){
                res.pop_back();
            }else{
                res+=c;
            }
            st.pop();
        }
        return res;
    }
};