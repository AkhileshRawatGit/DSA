class Solution {
public:
    int check(int n){
        int sum=0;
        while(n>0){
            sum+=n%10;
            n=n/10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(check(nums[i])==i) return i;
        }
        return -1;
    }
};