class Solution {
public:
vector<string> keypad = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    void generateKey(int index, string dig, vector<string>& res, string temp){
        if(index == dig.size()) {
            res.push_back(temp);
            return;
        }
        string letters = keypad[dig[index]-'0'];
        for(char letter: letters){
            generateKey(index+1,dig,res,temp+letter);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return res;
        generateKey(0,digits,res,"");
        return res;
    }
};