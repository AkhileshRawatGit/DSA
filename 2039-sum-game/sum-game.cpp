class Solution {
public:
    bool sumGame(string num) {
        int n=num.size()/2;
        int l=0;
        int r=0;
        int sum1=0;
        int sum2=0;
        for(int i=0;i<n;i++){
            if(num[i]=='?') l++;
            else sum1+=num[i]-'0';
        }
        for(int i=n;i<num.size();i++){
            if(num[i]=='?') r++;
            else sum2+=num[i]-'0';
        }
        if((l+r)%2!=0) return true;

        int diff=sum1-sum2;
        int bal= ((r-l)/2)*9;

        if(diff==bal) return false;
        return true;

    }
};