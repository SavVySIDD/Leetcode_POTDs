class Solution {
    vector<vector<int>>dp;
    int solve(string& word1, string& word2, int i, int j){
        if(i==word1.size()) return word2.size()-j; //remaining extra words
        if (j>=word2.size()) return word1.size()-i;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]){
            return dp[i][j] =  solve(word1,word2,i+1,j+1);
        }
        return dp[i][j] = 1+min(solve(word1,word2,i+1,j), solve(word1,word2,i,j+1));
    }
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        dp.resize(n1,vector<int>(n2,-1));
        return solve(word1,word2,0,0);
    }
};