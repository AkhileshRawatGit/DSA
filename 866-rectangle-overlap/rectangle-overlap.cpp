class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        
        int a=max(rec1[0],rec2[0]);
        int b=max(rec1[1],rec2[1]);
        int c=min(rec1[2],rec2[2]);
        int d=min(rec1[3],rec2[3]);
        if(c-a>=1 && d-b>=1) return true; 
        return false;
    }
};