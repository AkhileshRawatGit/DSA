class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // first i will find those array who is not less than k
        //  total - not less than ===>> less than

        if (k <=1)
            return 0;
        int mini = *min_element(nums.begin(), nums.end());
        if (mini > k)
            return 0;
        int find = 0;
        int i = 0;
        int j = 0;
        int product = 1;
        while (j < nums.size()) {
            product = product * nums[j];
            while (product >= k) {
                find += nums.size() - j;
                product = product / nums[i];
                i++;
            }
            j++;
        }
        int total = (nums.size() * (nums.size() + 1)) / 2;
        return total - find;
    }
};