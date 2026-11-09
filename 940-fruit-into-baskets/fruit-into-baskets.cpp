class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mp;
        int i=0;
        int j=0;
        int maxi=0;
        while(j<fruits.size()){
            mp[fruits[j]]++;
            while(mp.size()>2){
                maxi=max(maxi,j-i);
                mp[fruits[i]]--;
                if(mp[fruits[i]]==0) mp.erase(fruits[i]);
                i++;
            }
            j++;
        }
        return max(maxi,j-i);
    }
};