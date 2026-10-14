class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum > 9*num) return "";
        int req = sum/9;
        int rem = sum%9;
        string s(req,'9');
        
        if(rem > 0) s.push_back(rem+'0');

        while(s.size()<num) s.push_back('0');
        return s;
    }
};