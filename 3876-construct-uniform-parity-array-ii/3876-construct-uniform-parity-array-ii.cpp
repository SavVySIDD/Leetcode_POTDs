class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX;
        bool oddFound =false;
        for(auto&it:nums1){
            if(it%2!=0){
                oddFound = true;
                minOdd = min(it,minOdd);
            }
        }
        if(!oddFound) return true;
        for(auto&it:nums1){
            if(it%2==0 && it < minOdd) return false;
        }
        return true;
    }
};