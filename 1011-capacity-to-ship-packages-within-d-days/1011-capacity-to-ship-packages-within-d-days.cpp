class Solution {
    int check(vector<int>& weights, int allowed){
        int count =0;
        int res =1;
        int i=0,n = weights.size();
        while(i<n){
            count+=weights[i];
            if(count>allowed){
                count = weights[i];
                res++;
            }
            i++;
        }
        return res;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low =*max_element(weights.begin(), weights.end());;
        int res =0;
        int high = accumulate(begin(weights),end(weights),0);
        while(low<=high){
            int mid = low+(high-low)/2;
            if(check(weights,mid)<=days){
                res = mid;
                high = mid-1;
            }
            else{
                low =mid+1;
            }
        }
        return res;
    }
};