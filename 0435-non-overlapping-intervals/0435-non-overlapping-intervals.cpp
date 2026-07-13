class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        int count =0;
        int prevEnd = intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]<prevEnd){
                count++;
                prevEnd = min(intervals[i][1],prevEnd); // because we want to remove the one which ends early in order to minimise the number of removals
            }
            else{
                prevEnd = intervals[i][1];
            }
        }
        return count;
    }
};