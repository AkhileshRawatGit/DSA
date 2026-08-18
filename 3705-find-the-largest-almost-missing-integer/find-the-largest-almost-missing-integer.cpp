class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<=nums.size()-k;i++){
            set<int>st;
            for(int j=i;j<=i+k-1;j++){
                st.insert(nums[j]);
            }
            for(auto&k:st){
                mp[k]++;
            }
        }
        int maximum=INT_MIN;
        for(auto &i:mp){
            if(i.second==1){
                maximum=max(maximum,i.first);
            }
        }
        if(maximum==INT_MIN) return -1;
        return maximum;
    }
};