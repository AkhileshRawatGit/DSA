class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i]=(nums[i]*nums[i]);
        }
        // for(int i=0;i<nums.size();i++){
        //     cout<<nums[i]<<" ";
        // }
        sort(nums.begin(),nums.end());
        int n=nums.size()/2;
        //cout<<n<<" ";
        if(nums.size()%2!=0){
            n=n+1;
        }
        int m=nums.size()-n;
        long long ans1=0;
        long long ans2=0;
        for(int i=0;i<m;i++){
            ans1+=nums[i];
        }
        for(int j=m;j<nums.size();j++){
            ans2+=nums[j];
        }
        return ans2-ans1;
        
    }
};