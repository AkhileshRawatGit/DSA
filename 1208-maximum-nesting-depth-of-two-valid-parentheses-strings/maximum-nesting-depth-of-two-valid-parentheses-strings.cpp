class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans;
        stack<pair<char, int>> st;
        st.push({seq[0], 0});
        ans.push_back(0);
        for (int i = 1; i < seq.size(); i++) {
            if (st.size() == 0) {
                st.push({seq[i], 0});
                ans.push_back(0);
                continue;
            }
            if (!st.empty() && st.top().first == '(' && seq[i] == ')') {
                ans.push_back(st.top().second);
                st.pop();
            }
            if (!st.empty() &&st.top().first == '(' && seq[i] == '(') {
                if (st.top().second == 1) {
                    ans.push_back(0);
                    st.push({seq[i], 0});
                }
                else{
                    ans.push_back(1);
                    st.push({seq[i],1});
                }
            }
        }
        return ans;
    }
};