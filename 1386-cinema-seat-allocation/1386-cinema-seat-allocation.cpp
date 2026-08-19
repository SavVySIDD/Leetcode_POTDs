//T.C : O(N), N = reservedSeats.size()
//S.C : O(N), for storing reswerved seats in map (in form of unordered_set)
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> mp; //row -> seats in each row booked

        for(auto& reservedSeat : reservedSeats) {
            int row  = reservedSeat[0];
            int seat = reservedSeat[1];

            mp[row].insert(seat);
        }

        int result = (n - mp.size()) * 2; // complete empty rows directly fill 2 groups

        for(auto& [row, bookedSeats] : mp) {

            auto isAvailable = [&](int seats){
                return !bookedSeats.count(seats);
            };

            bool grpA = isAvailable(2) && isAvailable(3) && isAvailable(4) & isAvailable(5);
            bool grpB = isAvailable(4) && isAvailable(5) && isAvailable(6) & isAvailable(7);
            bool grpC = isAvailable(6) && isAvailable(7) && isAvailable(8) & isAvailable(9);

            if(grpA && grpC)
                result += 2;
            else if(grpA || grpB || grpC)
                result += 1;

        }

        return result;
    }
};

