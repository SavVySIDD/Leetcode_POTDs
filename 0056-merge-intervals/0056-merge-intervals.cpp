class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end());
        // 3,6,10,18
        // 1,2,8,15
        int presentEnd, presentStart;
        for(int i=0;i<n;i++){
            int start = intervals[i][0], end = intervals[i][1];
            if(res.empty() || start > res.back()[1]){
                res.push_back(intervals[i]);
            }
            else{
                res.back()[1] = max(end,res.back()[1]);
            }  
        }
        return res;
    }
};