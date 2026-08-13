class Solution {
public:
    int maxProduct(int n) {
        int maxi=0;
        string s=to_string(n);
        for(int i=0;i<s.size()-1;i++){
            for(int j=i+1;j<s.size();j++){
                maxi=max(maxi,((s[i]-'0')*(s[j]-'0')));
            }
        }
        return maxi;
    }
};