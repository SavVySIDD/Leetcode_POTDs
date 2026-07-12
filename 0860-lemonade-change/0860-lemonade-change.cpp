class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count5=0, count10=0, count20=0;
        for(int i:bills){
            if(i==5)
            { count5++;}
            else if(i==10 && count5){
                count5--;
                count10++;
            }
            else if(i==20 && count10 && count5){
                count5--;
                count10--;
                count20++;
            }
            else if(i==20 && count5>=3){
                count5-=3;
                count20++;
            }
            else{
                return false;
            }
        }
        return true;
    }
};