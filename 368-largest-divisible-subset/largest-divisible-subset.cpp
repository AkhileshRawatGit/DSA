class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> lds(n, 1);
        vector<int> index(n, -1);
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 || nums[j] % nums[i] == 0) {
                    if (lds[i] < 1 + lds[j]) {
                        lds[i] = max(lds[i], 1 + lds[j]);
                        index[i] = j;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            cout << index[i] << " ";
        }
        int maxI = *max_element(lds.begin(), lds.end());
        int maxi=-1;
        for (int i = 0; i < n; i++) {
            if (lds[i] == maxI)
                maxi = i;
        }
        cout<<maxi;
        vector<int> ans;

        while (maxi != -1) {
            ans.push_back(nums[maxi]);
            maxi = index[maxi];
        }
        return ans;
    }
};