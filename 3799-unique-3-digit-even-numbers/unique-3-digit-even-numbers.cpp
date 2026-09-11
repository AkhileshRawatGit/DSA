class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int count = 0;
        set<string> res;
        for (int i = 0; i < digits.size(); i++) {
            for (int j = 0; j < digits.size(); j++) {
                for (int k = 0; k < digits.size(); k++) {
                    if (i != j && j != k && k != i) {
                        string s = "";
                        string a = to_string(digits[i]);
                        string b = to_string(digits[j]);
                        string c = to_string(digits[k]);
                        s = s + a + b + c;
                        cout << s << " ";
                        res.insert(s);
                    }
                }
            }
        }
        for (auto& i : res) {
            if (i[0] != '0') {
                int a = stoi(i);
                if (a % 2 == 0)
                    count++;
            }
        }
        return count;
    }
};