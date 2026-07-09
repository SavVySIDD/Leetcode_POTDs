class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res;
        int n = intervals.size();
        for(int i=0;i<n;i++){
            int pStart = intervals[i][0], pEnd = intervals[i][1];
            int cnt =0;
            while(i+cnt<n && pEnd>= intervals[i+cnt][0]){
                pEnd = max(pEnd,intervals[i+cnt][1]);
                cnt++;
            }
            i+=cnt-1;
            res.push_back({pStart,pEnd});
        }
        return res;
    }
};