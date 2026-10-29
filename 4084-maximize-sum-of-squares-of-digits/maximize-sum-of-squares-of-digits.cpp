class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans="";
        while(num>0){
            if(sum<9){
                ans+=to_string(sum);
                sum=0;
                num--;
                break;
            }
            else{
                ans+='9';
                sum-=9;
            }
            num--;
        }
        while(num>0){
            ans+='0';
            num--;
        }
        return sum!=0?"":ans;
    }
};