class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);

        string t;
        int sum = 0;

        for(char c : s) {
            if(c != '0') {
                t += c;
                sum += c - '0';
            }
        }
        if(t.size()==0) return 0;

        return 1LL * sum * stoll(t);
    }
};