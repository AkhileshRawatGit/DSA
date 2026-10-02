class Solution {
public:
    void generate(vector<string>& result, string s, int open, int close,
                  int n) {
        if (open == n && close == n) {
            result.push_back(s);
            return;
        }
        if (open < n) {
            
            generate(result, s+'(', open + 1, close, n);
        }
        if (close < open) {
            generate(result, s+')', open, close + 1, n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string s = "";
        generate(result, s, 0, 0, n);
        return result;
    }
};