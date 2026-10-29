class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>9LL*num) return "";
        string ans;
        ans.reserve(num);
        while(num>0){
            if(sum<9){
                ans+=to_string(sum);
                sum=0;
            }
            else{
                ans+='9';
                sum-=9;
            }
            num--;
        }
        return sum!=0?"":ans;
    }
};