class Solution {
public:
    int totalOperation(string s,string a){
        if(s==a) return 0;
        string left=s;
        sort(left.begin(),left.end()-1);
        string right=s;
        sort(right.begin()+1,right.end());
        int l=INT_MAX-1;
        int r=INT_MAX-1;
        if(left!=s){
            l=totalOperation(left,a);
        }
        if(right!=s){
            r=totalOperation(right,a);
        }
        return 1+min(l,r);
    }
    int minOperations(string s) {
        string a=s;
        sort(a.begin(),a.end());
        if(a==s) return 0;
        return totalOperation(s,a)==INT_MAX?-1:totalOperation(s,a);
    }
};