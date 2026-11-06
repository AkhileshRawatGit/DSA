class Solution {
public:
    static bool customSort(const vector<int>& A, const vector<int>& B) {
        return A[1] < B[1];
    }

    vector<int> countServers(int n, vector<vector<int>>& logs,
                             int x, vector<int>& queries) {

        sort(logs.begin(), logs.end(), customSort);

        vector<pair<int,int>> qs;

        for (int i = 0; i < queries.size(); i++) {
            qs.push_back({queries[i], i});
        }

        sort(qs.begin(), qs.end());

        vector<int> res(queries.size());
        unordered_map<int,int> mp;

        int i = 0, j = 0;

        for (int k = 0; k < qs.size(); k++) {

            int lower = qs[k].first - x;
            int upper = qs[k].first;

            // Add logs within upper limit
            while (j < logs.size() && logs[j][1] <= upper) {
                mp[logs[j][0]]++;
                j++;
            }

            // Remove logs outside lower limit
            while (i < j && logs[i][1] < lower) {
                mp[logs[i][0]]--;

                if (mp[logs[i][0]] == 0) {
                    mp.erase(logs[i][0]);
                }

                i++;
            }

            res[qs[k].second] = n - mp.size();
        }

        return res;
    }
};