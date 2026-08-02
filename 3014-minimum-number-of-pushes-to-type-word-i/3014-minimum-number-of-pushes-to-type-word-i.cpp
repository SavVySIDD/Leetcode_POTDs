class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int times = 1;
        int res =0;
        while(n){
            if(n>8){ 
                res+=8*times;
                n-=8;
            }else{
                res+=n*times;
                n=0;
            }
            times++;
        }
        return res;
    }
};

//"xycdefgh ij"