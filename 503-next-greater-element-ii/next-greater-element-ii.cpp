class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //int maxi=*max_element(nums.begin(),nums.end());
        stack<int>st;
        for(int i=nums.size()-1;i>=0;i--){
            st.push(nums[i]);
        }
        vector<int>res(nums.size());
        for(int i=nums.size()-1;i>=0;i--){
            while(st.size()>0 && nums[i]>=st.top()){
                st.pop();
            }
            if(st.size()==0){
                res[i]=-1;
            }
            else{
                res[i]=st.top();
            }
            st.push(nums[i]);
        }
        return res;
    }
};