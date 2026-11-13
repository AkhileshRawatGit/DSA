class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        vector<vector<string>> ans;
        int i = 0;
        int j = 0;
        string a = "";
        string b = "";
        while (i < s1.size() && j < s2.size()) {

            if (s1[i] == s2[j]) {
                if (a.size() > 0 && b.size() > 0) {
                    vector<string> res;
                    res.push_back(a);
                    res.push_back(b);
                    ans.push_back(res);
                    a = "";
                    b = "";
                }
            } else {
                a += s1[i];
                b += s2[j];
            }
            i++;
            j++;
        }
        if(a.size()>0 && b.size()>0){
            ans.push_back({a,b});
        }
        return ans;
    }
};