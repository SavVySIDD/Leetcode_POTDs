class Solution {
    int check(vector<int>& bloomDay, int k, int t){
        int count =0;
        int res =0;
        int n = bloomDay.size();
        for(int i=0;i<n;i++){   
            if(bloomDay[i]>t){
                res+= count/k;
                count =0;
            }
            else
            count++;
        }
        res+=count/k; //Iwas missing this last segment
        return res;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        if(bloomDay.size()< 1LL*m*k) return -1;
        int res =0;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(check(bloomDay,k,mid)>=m){
                res = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return res;
    }
};