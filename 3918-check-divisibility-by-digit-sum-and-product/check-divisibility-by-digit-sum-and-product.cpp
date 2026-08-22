class Solution {
public:
    bool checkDivisibility(int n) {
        int prod=1;
        int sum=0;
        int a=n;
        while(n>0){
            sum+=n%10;
            prod*=n%10;
            n=n/10;
        }
        cout<<prod<<" "<<sum<<" ";

        if(a%(prod+sum)==0) return true;
        return false;
    }
};