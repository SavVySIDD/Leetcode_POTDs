class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end());
        // 3,6,10,18
        // 1,2,8,15
        for(int i=0;i<n;i++){
            int start = intervals[i][0]; int end = intervals[i][1];
            if(res.empty() || res.back()[1] < start){
                res.push_back(intervals[i]);
            }else{
                res.back()[1] = max(res.back()[1],end);
            }
        }
        return res;
    }
};