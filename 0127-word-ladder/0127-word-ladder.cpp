class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st;
        for(auto&it:wordList){
            st.insert(it);
        }
        st.erase(beginWord);
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty()){
            string word = q.front().first;
            int seq = q.front().second;
            q.pop();
            if(word == endWord){
                return seq;
            }
            for(int i=0;i<word.size();i++){
                char original = word[i];
                for(char c= 'a';c<='z';c++){
                    word[i] = c;
                    if(st.count(word)){
                        st.erase(word);
                        q.push({word,seq+1});
                    }
                }
                word[i]=original;
            }
        }
        return 0;
    }
};