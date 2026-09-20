class Solution {
public:
    int reverseDegree(string s) {
        int n = s.size();
        int ind = 1;
        int res = 0;
        for(auto& c:s){
            int x ='z'-c+1;
            res  += x*ind;
            ind++;
        }
        return res;
    }
};