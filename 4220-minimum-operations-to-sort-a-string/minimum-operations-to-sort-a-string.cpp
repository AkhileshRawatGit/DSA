class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        string a = s;
        sort(a.begin(), a.end());

        if (s == a) return 0;
        if (n == 2) return -1; 

        int minIndex = 0;   
        int maxIndex = 0;  

        for (int i = 1; i < n; i++) {
            if (s[i] < s[minIndex])
                minIndex = i;

            if (s[i] >= s[maxIndex])   
                maxIndex = i;
        }

        if (minIndex == 0 || maxIndex == n - 1)
            return 1;

        if (minIndex != n - 1 || maxIndex != 0)
            return 2;

        return 3;
    }
};