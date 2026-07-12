class Solution {
public:
    bool checkValidString(string s) {
        int maxCount = 0; // worst case most unmatched
        int minCount =0; // best case fewest unmatched and they can't be negative
        for(char c:s){
            if(c=='('){
                maxCount++;
                minCount++;
            } 
            else if(c==')') {
                maxCount--;
                minCount--;
            }
            else{ // asterix gives the total range that we can achieve.
                maxCount++;
                minCount--;
            }
            if(minCount<0) minCount = 0;//It can go negative if we assume too many closings — but in reality, we can just treat those extra ) as * or empty.
            if(maxCount<0) return false; // Its like too many ')' or like starting with ')';
        }
        if(minCount ==0 ) return true; // if the min not zero so we cannot achive the proper order.
        return false;
    }
};