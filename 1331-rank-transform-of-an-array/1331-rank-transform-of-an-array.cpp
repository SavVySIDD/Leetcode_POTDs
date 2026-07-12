class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<pair<int,int>> temp;
        for(int i=0;i<n;i++)
        temp.push_back({arr[i],i});
        sort(temp.begin(),temp.end());
        int rank=1;
        for(int i=0;i<n;i++)
        {
            if(i>0&&temp[i].first!=temp[i-1].first)
            rank++;
            arr[temp[i].second]=rank;
        }
        return arr;
    }
};