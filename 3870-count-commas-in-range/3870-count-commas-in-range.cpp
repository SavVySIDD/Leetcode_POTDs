class Solution {
public:
    int countCommas(int n) {
        string s = to_string(n);
        int res = 0;
        if(n>=1000){
            res+=n-1000+1;
        }
        return res;
    }
};