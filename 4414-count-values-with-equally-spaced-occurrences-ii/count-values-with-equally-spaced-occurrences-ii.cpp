class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int count = 0;
        int maxi = *max_element(nums.begin(), nums.end());
        unordered_map<int, vector<int>> ans;
        for (int i = 0; i < nums.size(); i++) {
            ans[nums[i]].push_back(i);
        }
        for (auto& i : ans) {
            if (i.second.size() >= 3) {
                vector<int>& v = i.second;
                int space = v[1] - v[0];
                int k = 1;
                int l = 2;
                bool flag = true;
                while (l < v.size()) {
                    if ((v[l] - v[k]) != space) {
                        flag = false;
                        break;
                    }
                    k++;
                    l++;
                }
                if (flag) {
                    count++;
                }
            }
        }
        return count;
    }
};