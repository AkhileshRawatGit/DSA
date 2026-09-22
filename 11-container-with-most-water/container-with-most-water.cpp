class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int maxi=0;
        while(i<j){
            int mini=min(height[i],height[j]);
            maxi=max(maxi,mini*(j-i));
            if(height[i]<=height[j]) i++;
            else j--;
        }
        return maxi;
    }
};