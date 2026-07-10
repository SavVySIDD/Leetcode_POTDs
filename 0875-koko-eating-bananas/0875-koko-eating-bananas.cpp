class Solution {
    long long check(vector<int>&piles,int k){
        long long h = 0;
        for(auto&it:piles){
            h+=it/k;
            if(it%k!=0) h++;
        }
        return h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int n = piles.size();
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        int ans = -1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(check(piles,mid)<=h){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};