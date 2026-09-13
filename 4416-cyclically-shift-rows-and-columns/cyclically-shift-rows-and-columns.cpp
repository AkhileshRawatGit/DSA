class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid,
                                    vector<int>& rowShift,
                                    vector<int>& colShift) {
        //vector<vector<int>> ans(n, vector<int>(n, 0));
        // int n=grid.size();
        for (int i = 0; i < rowShift.size(); i++) {
            int k = rowShift[i] % n;
            rotate(grid[i].begin(), grid[i].begin() + k, grid[i].end());
        }

        for(int i=0;i<colShift.size();i++){
            vector<int>temp;
            for(int j=0;j<n;j++){
                temp.push_back(grid[j][i]);
            }
            int k = colShift[i] % n;
            rotate(temp.begin(), temp.begin() + k, temp.end());
            for(int j=0;j<temp.size();j++){
                grid[j][i]=temp[j];
            }
        }
        return grid;
    }
};