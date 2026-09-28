class Solution {
public:
    int maxDepth(string s) {
        int res = INT_MIN;
        int cnt = 0;
        for(auto&it:s){
            if(it == '('){
                cnt++;
            }else if(it == ')'){
                cnt--;
            }
            res = max(res,cnt);
        }
        return res;
    }
};