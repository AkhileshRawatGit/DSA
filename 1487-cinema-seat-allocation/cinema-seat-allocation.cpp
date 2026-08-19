class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < reservedSeats.size(); i++) {
            mp[reservedSeats[i][0]].push_back(reservedSeats[i][1]);
        }
        int total = n * 2;
        for (auto& i : mp) {
            int a1 = true;
            int b1 = true;
            int c1 = true;
            for (auto& j : i.second) {
                if (j == 2 || j == 3 || j == 4 || j == 5)
                    a1 = false;
                if (j == 4 || j == 5 || j == 6 || j == 7)
                    b1 = false;
                if (j == 6 || j == 7 || j == 8 || j == 9)
                    c1 = false;
            }
            if (a1 && c1) {
            } else if (a1 || b1 || c1) {
                total--;
            } else {
                total -= 2;
            }
        }
        return total;
    }
};