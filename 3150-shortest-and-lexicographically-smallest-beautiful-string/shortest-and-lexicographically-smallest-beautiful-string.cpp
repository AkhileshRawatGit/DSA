class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        int i=0;
        int j=0;
        vector<string>result;
        int resultSize=INT_MAX;
        while(i<=s.size()-k){
            int onsCount=0;
            while(j<s.size()){
                if(s[j]=='1') onsCount++;
                if(onsCount==k && j-i+1<=resultSize){
                    string a=s.substr(i,j-i+1);
                    result.push_back(a);
                    resultSize=j-i+1;
                    break;
                }
                j++;
            }
            i++;
            j=i;
        }
        sort(result.begin(),result.end());
        int index=-1;
        int count=INT_MAX;
        for(int i=0;i<result.size();i++){
            if(result[i].size()<count){
                index=i;
                count=result[i].size();
            }
        }
        if(index==-1) return {};
        return result[index];
    }
};