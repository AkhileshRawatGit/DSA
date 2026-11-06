class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0;
        int j=0;
        unordered_map<int,int>mp;
        int maxi=0;
        while(j<fruits.size()){
            mp[fruits[j]]++;
            j++;
            while(mp.size()>2){
                mp[fruits[i]]--;
                if(mp[fruits[i]]==0) mp.erase(fruits[i]);
                i++;
            }
            maxi=max(maxi,j-i);
        }
        return max(maxi,j-i);
    }
};