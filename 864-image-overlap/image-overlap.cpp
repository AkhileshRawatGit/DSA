class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        map<pair<int,int>,int>A,B;
        for(int i=0;i<img1.size();i++){
            for(int j=0;j<img1.size();j++){
                if(img1[i][j]==1) A[{i,j}]++;
            }
        }
        for(int i=0;i<img2.size();i++){
            for(int j=0;j<img2.size();j++){
                if(img2[i][j]==1) B[{i,j}]++;
            }
        }

        map<pair<int,int>,int>mp;
        for(auto&i:A){
            for(auto&j:B){
                int a=j.first.first-i.first.first;
                int b=j.first.second-i.first.second;
                mp[{a,b}]++;
            }
        }
        int count=0;
        for(auto&i:mp){
            if(i.second>count) count=i.second;
        }
        return count;
    }
};