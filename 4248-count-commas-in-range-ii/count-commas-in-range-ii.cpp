class Solution {
public:
    long long countCommas(long long n) {
        string s = to_string(n);
        if (s.size() < 4)
            return 0;
        if (s.size() >= 4 && s.size() <= 6)
            return n - 999;
        if (s.size() >= 7 && s.size() <= 9)
            return (999999 - 999) + (n - 999999) * 2;
        if (s.size() >= 10 && s.size() <= 12)
            return (n - 999999999) * 3 + (999999999 - 999999) * 2 +
                   (999999 - 999);
        if (s.size() >= 13 && s.size() <= 15)
            return (n - 999999999999) * 4 + (999999999999 - 999999999) * 3 +
                   (999999999 - 999999) * 2 + (999999 - 999);
        if (s.size() >= 16 && s.size() <= 18)
            return (n - 999999999999999) * 5 +
                   (999999999999999 - 999999999999) * 4 +
                   (999999999999 - 999999999) * 3 + (999999999 - 999999) * 2 +
                   (999999 - 999);
        return -1;
    }
};