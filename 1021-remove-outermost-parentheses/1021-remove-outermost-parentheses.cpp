class Solution {
public:
    string removeOuterParentheses(string s) {
        //vector <string> str;
        string result;
        int count = 0;
        for(char c: s){
            if(c == '('){
                if(count > 0){
                    result+= c;
                }
                count++;
            }
            else if(c== ')'){
                if(count > 1){
                    result+=c;
                }
                count--;

            }
            
        }
        return result;
    }
};