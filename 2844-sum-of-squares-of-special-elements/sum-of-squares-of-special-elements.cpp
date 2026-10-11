class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        vector<int> index;
        for (int i = 1; i <= nums.size(); i++) {
            if (nums.size() % i == 0) {
                index.push_back(nums[i-1]);
            }
        }
        int sum = 0;
        for (int i = 0; i < index.size(); i++) {
            sum += (index[i] * index[i]);
        }
        return sum;
    }
};