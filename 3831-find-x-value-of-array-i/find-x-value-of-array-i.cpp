class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long>result(k,0);
        vector<long long>prevCount(k,0);

        for(int i=0;i<n;i++){

            vector<long long>currCount(k,0);
            int startingRemider=nums[i]%k;
            currCount[startingRemider]++;
            for(int r=0;r<k;r++){
                int newReminder=((long long)r*(nums[i])%k)%k;
                currCount[newReminder]+=prevCount[r];
            }
            prevCount=currCount;
            for(int x=0;x<k;x++){
                result[x]+=prevCount[x];
            }
        }
        return result;
    }
};