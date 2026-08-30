class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        // Akhilesh
        int maxi=*max_element(nums.begin(),nums.end());
        int mini=*min_element(nums.begin(),nums.end());
        int front=0;  //left to right
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxi || nums[i]==mini){
                front=i+1;
            }
        }
        int back=0;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]==maxi || nums[i]==mini){
                back=nums.size()-i;
            }
        }
        int front1=0;
        int back1=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxi || nums[i]==mini){
                front1+=i+1;
                break;
            }
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]==maxi || nums[i]==mini){
                back1+=nums.size()-i;
                break;
            }
        }
        return min(front,min(back,front1+back1));
    }
};