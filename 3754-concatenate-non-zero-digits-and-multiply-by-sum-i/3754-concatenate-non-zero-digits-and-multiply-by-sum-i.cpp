class Solution {
public:
    long long sumAndMultiply(int n) {
        string s;
        while(n){
            if(n%10 != 0){
                s+=to_string(n%10);
            }
            n/=10;
        }
        reverse(s.begin(),s.end());
        if(s.size()==0) return 0;
        int sum =0;
        for(auto&it:s){
            sum+=it-'0';
        }
        return 1LL*sum*stoi(s);
    }
};