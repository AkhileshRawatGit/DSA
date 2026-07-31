class Solution {
public:
    bool checkSubSequence(string& s1, string& s2) {
        if(s2.size()-s1.size()>=2 ||s2.size()-s1.size()==0) return false;
        int i = 0;
        int j = 0;
        while (j < s2.size() && i < s1.size()) {
            if (s1[i] == s2[j]) {
                i++;
                j++;
            } else
                j++;
        }
        if (i != s1.size())
            return false;
        return true;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            if (a.size() == b.size())
                return a < b;
            return a.size() < b.size();
        });
        int n = words.size();
        vector<int> dp(n, 1);

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (checkSubSequence(words[j], words[i])) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                    //cout<<dp[i];
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};