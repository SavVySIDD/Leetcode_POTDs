class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
         vector<vector<int>> res;
        int i=0,n = intervals.size();
        // intervals ending before the newInterval
        while(i<n && intervals[i][1] < newInterval[0]){
            res.push_back(intervals[i]);
            i++;
        }
        
        //overlapping intervals
        while(i<n && intervals[i][0]<=newInterval[1]){
            newInterval[0] = min(intervals[i][0],newInterval[0]);
            newInterval[1] = max(intervals[i][1],newInterval[1]);
            i++;
        }
        res.push_back({newInterval[0],newInterval[1]});
        
        while(i<n){
            res.push_back(intervals[i]);i++;
        }
        return res;
    }
};