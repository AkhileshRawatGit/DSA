class NumArray {
public:
    vector<int> tree;
    int n;

    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n);
        buildTree(0, 0, n - 1, nums);
    }

    void buildTree(int node, int start, int end, vector<int>& nums) {
        if (start == end) {
            tree[node] = nums[start];
            return;
        }

        int mid = start + (end - start) / 2;

        buildTree(2 * node + 1, start, mid, nums);
        buildTree(2 * node + 2, mid + 1, end, nums);

        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    void updateQuery(int node, int start, int end, int index, int val) {

        if (index < start || index > end)
            return;

        if (start == index && end == index) {
            tree[node] = val;
            return;
        }

        int mid = start + (end - start) / 2;

        if (index > mid)
            updateQuery(2 * node + 2, mid + 1, end, index, val);
        else
            updateQuery(2 * node + 1, start, mid, index, val);

        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    void update(int index, int val) {
        updateQuery(0, 0, n - 1, index, val);
    }

    int sumQuery(int node, int left, int right, int start, int end) {

        if (end < left || start > right)
            return 0;

        if (left <= start && end <= right)
            return tree[node];

        int mid = start + (end - start) / 2;

        int leftSum = sumQuery(
            2 * node + 1,
            left,
            right,
            start,
            mid
        );

        int rightSum = sumQuery(
            2 * node + 2,
            left,
            right,
            mid + 1,
            end
        );

        return leftSum + rightSum;
    }

    int sumRange(int left, int right) {
        return sumQuery(0, left, right, 0, n - 1);
    }
};