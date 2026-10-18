class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ni=0;
        int nj=0;
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        visited[0][0]=true;
        while(true){
            int i=ni;
            int j=nj;
            char ch=grid[i][j];
            if(ch=='L'){
                j--;
            }
            else if(ch=='R'){
                j++;
            }
            else if(ch=='U'){
                i--;
            }
            else if(ch=='D'){
                i++;
            }
            if(i < 0 || i >= m || j < 0 || j >= n){
                break;
            }
            if (visited[i][j])
                break;
            ni=i;
            nj=j;
            visited[ni][nj]=true;
        }
        return {ni,nj};
    }
};