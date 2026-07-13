class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        
        for(char ch:num){
            while(!st.empty() && st.top()>ch && k>0){
                st.pop();
                k--;
            }
            st.push(ch);
        }

        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }
        string res;
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }

        reverse(res.begin(),res.end());

        int i=0;
        while(i<res.size() && res[i]=='0')
            i++;
        res = res.substr(i);
        return res.empty()?"0":res;
    }
};