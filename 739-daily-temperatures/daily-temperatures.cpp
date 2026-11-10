class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        vector<int> res(temperatures.size());
        res[temperatures.size() - 1] = 0;
        st.push(
            {temperatures[temperatures.size() - 1], temperatures.size() - 1});
        int i = temperatures.size() - 2;
        while (st.size() > 0 && i >= 0) {
            int a = temperatures[i];
            while (st.size() > 0 && a >= st.top().first) {
                st.pop();
            }
            if (st.size() == 0) {
                res[i] = 0;
            } else {
                res[i] = st.top().second - i;
            }
            st.push({a, i});
            i--;
        }
        return res;
    }
};