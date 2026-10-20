class Solution {
public:
    bool canBeSorted(vector<int>& dummy, int i, int r) {
        int breaks = 0;
        for (int j = i; j < r; j++) {
            if (dummy[j] > dummy[j + 1]) {
                breaks++;
            }
        }
        if (dummy[r] > dummy[i])
            breaks++;
        return breaks <= 1;
    }
    bool isSorted(vector<int>& nums, int k, vector<int>& res) {
        vector<int> dummy;
        for (int i = 0; i < nums.size(); i++) {
            dummy.push_back(nums[i]);
        }
        int n = nums.size();
        for (int s = 0; s < n; s += k) {
            int e = s + k - 1;

            if (!canBeSorted(dummy, s, e)) {
                return false;
            } else {
                int pos = s;

                for (int j = s; j < e; j++) {
                    if (dummy[j] > dummy[j + 1]) {
                        pos = j + 1;
                        break;
                    }
                }

                // Rotate current subarray
                rotate(dummy.begin() + s, dummy.begin() + pos,
                       dummy.begin() + e + 1);
            }
        }
        return dummy==res;
    }

    int sortableIntegers(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            res.push_back(nums[i]);
        }
        sort(res.begin(), res.end());
        int sum = 0;
        for (int i = 1; i <= nums.size(); i++) {
            if (nums.size() % i == 0) {
                if (isSorted(nums, i, res)) {
                    sum += i;
                }
            }
        }
        return sum;
    }
};

// class Solution {
// public:

//     bool canBeSorted(vector<int>& nums, vector<int>& target,
//                      int l, int r) {

//         int len = r - l + 1;

//         // Try every possible rotation
//         for (int shift = 0; shift < len; shift++) {

//             bool ok = true;

//             for (int j = 0; j < len; j++) {
//                 int idx = l + (shift + j) % len;

//                 if (nums[idx] != target[l + j]) {
//                     ok = false;
//                     break;
//                 }
//             }

//             if (ok) return true;
//         }

//         return false;
//     }

//     bool isSorted(vector<int>& nums, int k, vector<int>& res) {

//         int n = nums.size();

//         for (int s = 0; s < n; s += k) {

//             int e = s + k - 1;

//             if (!canBeSorted(nums, res, s, e)) {
//                 return false;
//             }
//         }

//         return true;
//     }

//     int sortableIntegers(vector<int>& nums) {

//         int n = nums.size();

//         vector<int> res = nums;
//         sort(res.begin(), res.end());

//         int sum = 0;

//         for (int k = 1; k <= n; k++) {

//             if (n % k == 0) {

//                 if (isSorted(nums, k, res)) {
//                     sum += k;
//                 }
//             }
//         }

//         return sum;
//     }
// };