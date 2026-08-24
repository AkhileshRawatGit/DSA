class Solution {
public:
    bool check(int n,int t){
        int prod=1;
        while(n>0){
            prod=prod*(n%10);
            n=n/10;
        }
        if(prod%t==0) return true;
        return false;
    }
    int smallestNumber(int n, int t) {
        for(int i=n;i<=100;i++){
            if(check(i,t)) return i;
        }
        return -1;
    }
};