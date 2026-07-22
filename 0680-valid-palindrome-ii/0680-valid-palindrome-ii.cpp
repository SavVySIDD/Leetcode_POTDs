class Solution {
    bool validPalindrome(string s, int left , int right){
        while(left<right){
            if(s[left]==s[right]){
                left++;right--;
            }else return false;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int count =0;
        int n = s.size();
        int left = 0, right = n-1;
        while(left<right){
            if(s[left]==s[right]){
                left++;
                right--;
            }
            else{
                return validPalindrome(s,left+1,right) || validPalindrome(s,left,right-1);
            }
        }
        return true;
    }
};