class Solution {
public:
    int minMoves(vector<int>& nums) {

        //greedy approach

        // int count=0;
        // int maxi=*max_element(nums.begin(),nums.end());
        // int mini=*min_element(nums.begin(),nums.end());
        // if(maxi==mini) return 0;
        // while(maxi!=mini){
        //     for(int i=0;i<nums.size();i++){
        //         if(nums[i]==maxi){
        //             nums[i]--;
        //             count++;
        //         }
        //     }
        //     maxi=*max_element(nums.begin(),nums.end());
        //     mini=*min_element(nums.begin(),nums.end());
        // }
        // return count;

        int count=0;
        int mini=*min_element(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]==mini) continue;
            count=count+(nums[i]-mini);
        }
        return count;
    }
};