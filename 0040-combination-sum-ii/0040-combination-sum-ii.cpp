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
        if(candidates[ind]>target) return;
        for(int i=ind;i<candidates.size();i++){
            if(candidates[i]>target) break;

            //to avoid repetition
            if(i>ind && candidates[i]==candidates[i-1]) continue;
            temp.push_back(candidates[i]);
            solve(candidates,target-candidates[i],temp,i+1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>temp;
        sort(begin(candidates),end(candidates));
        solve(candidates,target,temp,0);
        return res;
    }
};