class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int maxiArea=0;
        while(i<j){
            int area=min(height[i],height[j])*(j-i);
            maxiArea=max(maxiArea,area);
            if(height[i]<=height[j]) i++;
            else j--;
        }
        return maxiArea;
    }
};