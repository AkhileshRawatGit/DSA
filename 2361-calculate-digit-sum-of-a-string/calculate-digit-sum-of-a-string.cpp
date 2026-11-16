class Solution {
public:
    string add(string s,int st,int e){
        int add=0;
        for(int i=st;i<=e;i++){
            add=add+(s[i]-'0');
        }
        return to_string(add);
    }
    string digitSum(string s, int k) {
        string a=s;
        while(a.size()>k){
            string dummy="";
            int size = (a.size() + k - 1) / k;
            for(int i=0;i<size;i++){
                int st = i * k;
                int e = min(st + k - 1, (int)a.size() - 1);
                dummy+=add(a,st,e);
            }
            a=dummy;
        }
        return a;
    }
};