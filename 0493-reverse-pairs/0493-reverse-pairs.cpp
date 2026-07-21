class Solution {
    int count =0;
    void merge(vector<int>&arr, int left, int mid, int right){
     

        // Count reverse pairs
        int j = mid + 1;
        for (int i = left; i <= mid; i++) {
            while (j <= right && (long long)arr[i] > 2LL * arr[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }
        int n1 = mid-left+1;
        int n2 = right - (mid+1) +1;
        int k =left;
        vector<int>L(n1),R(n2);
        for(int i=0;i<n1;i++){
            L[i] = arr[k];
            k++;
        }
        for(int i=0;i<n2;i++){
            R[i] = arr[k];
            k++;
        }
        int i =0;
        j=0;
        k=left;
        while(i<n1 && j<n2){
            if(L[i]<=R[j]){
                arr[k++]=L[i++];
            }
            else{ // Right is smaller
                arr[k++]=R[j++];
            }
        }
        while(i<n1){
            arr[k++] = L[i++];
        }
        while(j<n2){
            arr[k++] = R[j++];
        }
    }
    void mergesort(vector<int>&arr,int low, int high){
        if(low>=high) return ;
        int mid = low+(high-low)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
public:
    int reversePairs(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);
        return count;
    }
};