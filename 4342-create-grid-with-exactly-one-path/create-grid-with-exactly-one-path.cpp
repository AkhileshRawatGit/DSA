class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>ans;
        for(int i=0;i<m;i++){
            string s="";
            if(i!=m-1){
                s+='.';
                for(int i=0;i<n-1;i++){
                    s+='#';
                }
            }
            else{
                for(int i=0;i<n;i++){
                    s+='.';
                }
            }
            ans.push_back(s);
        }
        return ans;
    }
};