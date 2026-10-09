class Solution {
public:
    int minInsertions(string s) {
        int open = 0;
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {
                open++;
            }
            else {
                // agar next bhi ')' hai -> proper "))"
                if (i + 1 < s.size() && s[i + 1] == ')') {
                    i++;

                    if (open > 0) {
                        open--;
                    }
                    else {
                        // "))" ke liye '(' chahiye
                        ans++;
                    }
                }
                else {
                    // single ')' hai, ek ')' insert karo
                    ans++;

                    if (open > 0) {
                        open--;
                    }
                    else {
                        // ab '(' bhi chahiye
                        ans++;
                    }
                }
            }
        }

        // bache hue '(' ke liye har ek ko "))" chahiye
        ans += open * 2;

        return ans;
    }
};