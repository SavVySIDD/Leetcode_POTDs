class Solution {
public:
    bool checkDivisibility(int n) {
        int original = n;
        int sum=0,prod=1;
        while(n){
            int lp = n%10;
            sum += lp;
            prod*= lp;
            n/=10;
        }
        int check = prod+sum;
        return (original%check)==0;
    }
};