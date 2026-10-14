class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum > 9*num) return "";
        string s = "";
        while(sum>0 && s.size() < num){
            int digit = min(9, sum);
            s.push_back('0' + digit);
            sum -= digit;
        }
        while(s.size()<num) s.push_back('0');
        return s;
    }
};