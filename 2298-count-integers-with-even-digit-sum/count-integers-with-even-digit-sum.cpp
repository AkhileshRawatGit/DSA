class Solution {
public:
    int countEven(int num) {
        int sum=0;
        int n=num;
        while(n>0){
            sum=sum+n%10;
            n/=10;
        }
        cout<<sum;
        return sum%2==0?num/2:(num-1)/2;
    }
};