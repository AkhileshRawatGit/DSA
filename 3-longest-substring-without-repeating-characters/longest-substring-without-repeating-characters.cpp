class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        

        // maintain the map 
        // iterate the in string and take the two pointer like slinding windown
        // i=0, j=0; if j is not present in map put in map and j++
        // if present find the size and i++
        //
        if(s.size()==0 || s.size()==1) return s.size(); 
        unordered_map<char,int>mp;
        int i=0;
        int j=0;
        int maxSize=1;
        while(j<s.size()){
            if(mp.find(s[j])!=mp.end()){
                i=max(i,mp[s[j]]+1);
                mp[s[j]]=j;
            }
            else{
                mp[s[j]]=j;
            
            }
            maxSize=max(maxSize,j-i+1);
            j++;
        }
        return maxSize;
    }
};