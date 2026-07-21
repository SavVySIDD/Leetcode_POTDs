class Solution {
public:
    int numberOfSubstrings(string s) {
        int lastSeen[3] = {-1,-1,-1};
        int count =0;
        int n = s.size();
        for(int i=0;i<n;i++){
            lastSeen[s[i]-'a'] = i;
            if(lastSeen[0]!=-1 && lastSeen[1]!=-1  && lastSeen[2]!=-1 ){
                count += 1 + min({lastSeen[0], lastSeen[1], lastSeen[2]});
                // adding everything at the left which is min+1;
                // basically every start upto the minLast seen is valid because all of them will be containing all the characters and 0 based indexing so added 1
            }
        }
        return count;
    }
};