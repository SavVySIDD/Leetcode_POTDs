class Solution {
public:
    int smallestNumber(int n, int t) {
        int low = n+1;
        for(int i=n;i<=101;i++){
            int temp =1;
            int j=i;
            while(j){
                temp*=j%10;
                j/=10;
            }
            if(temp%t==0) return i;
        }
        // int high = 101;
        // while(low<=high){
        //     int mid = low+(high-low)/2;
        //     if(mid%t==0){
        //         ans = mid;
        //         high = mid-1;
        //     }else if(mid)
        // }
        return -1;
    }
};