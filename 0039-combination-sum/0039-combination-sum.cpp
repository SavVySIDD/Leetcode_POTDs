class Solution {
    vector<vector<int>>res;
    void solve(vector<int>&candidates,int target,vector<int>&temp, int ind){
        if(target==0){
            res.push_back(temp);
            return;
        }
        if(ind>=candidates.size() || target<0){
            return;
        }

        //take the current candidate
        temp.push_back(candidates[ind]);
        solve(candidates,target-candidates[ind],temp,ind);

        //move further
        temp.pop_back();
        solve(candidates,target,temp,ind+1);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        solve(candidates,target,temp,0);
        return res;
    }
};