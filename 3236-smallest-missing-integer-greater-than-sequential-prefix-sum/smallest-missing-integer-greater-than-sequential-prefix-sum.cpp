class Solution {
public:
    int missingInteger(vector<int>& nums) {
        set<int>st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        int sum=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]-1==nums[i-1]){
                sum+=nums[i];
            }
            else break;
        }
        int largest=*max_element(nums.begin(),nums.end());
        for(int i=sum;i<=largest;i++){
            if(st.find(i)==st.end()) return i;
        }
        if(sum<=largest) return largest+1;
        else return sum;
    }

};