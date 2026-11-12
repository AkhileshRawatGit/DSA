class Solution {
public:
    long long isEat(vector<int>&piles,int n){
        long long count=0;
        for(int i=0;i<piles.size();i++){
            count=count+ceil((piles[i]+n-1)/n);
        }
        return count;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=*max_element(piles.begin(),piles.end());
        int l=1;
        int r=maxi;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isEat(piles,mid)<=h){
                r=mid-1;
            }
            else l=mid+1;
        }
        return l;
    }
};