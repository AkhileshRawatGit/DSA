class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1,
                               int k2) {

        vector<long long> ans(1e5+1, 0);

        for (int i = 0; i < nums1.size(); i++) {
            int d = abs(nums1[i] - nums2[i]);
            ans[d]++;
        }
        long long oper = (long long)(k1 + k2);
        for (int i = 1e5; i > 0 && oper > 0; i--) {
            long long countOps = min(ans[i], oper);
            ans[i] -= countOps;
            ans[i - 1] += countOps;
            oper -= countOps;
        }
        long long total = 0;
        for (int i = 1; i <= 1e5; i++) {
            total += (ans[i]* (long long)i * i);
        }
        return total;
    }
};