class Solution {
    vector<vector<int>>res;
    void solve(int k, int n, vector<int>&temp,int num){
        if(k==0 && n==0){
            res.push_back(temp);
            return;
        }
        if(k <= 0 || n <= 0) return;
        for(int i=num;i<=9;i++){
            if(i>n) break;
            temp.push_back(i);
            solve(k-1,n-i,temp,i+1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        solve(k,n,temp,1);
        return res;
    }
};