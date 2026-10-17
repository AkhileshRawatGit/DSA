class Solution {
public:
    int calculateSum(int n){
        int sum=0;
        while(n>0){
            sum+=(n%10);
            n=n/10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
    
        vector<int>res(nums.size());
        for(int i=0;i<nums.size();i++){
            res[i]=nums[i];
        }
        sort(res.begin(),res.end(),[this](int a,int b){
            int num1=calculateSum(a);
            int num2=calculateSum(b);
            if (num1 != num2)
                return num1 < num2;

            return a < b;
        });
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=i;
        }
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=res[i]){
                int index=mp[res[i]];
                mp[nums[i]] = index;
                mp[res[i]] = i;
                swap(nums[i],nums[index]);
                count++;
            }
        }
        return count;
    }
};