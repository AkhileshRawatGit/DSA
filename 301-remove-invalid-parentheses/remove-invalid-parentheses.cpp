// class Solution {
// public:
//     bool isValid(string s){
//         stack<char>st;
//         for(int i=0;i<s.size();i++){
//             if(s[i]=='('){
//                 st.push(s[i]);
//             }
//             else if(s[i]==')'){
//                 if(st.empty()){
//                     return false;
//                 }

//                 if(st.top()=='('){
//                     st.pop();
//                 }
//             }
//         }
//         if(st.empty()) return true;
//         return false;
//     }
//     void check(string &s,int ind,unordered_set<string>&res,string &a){
//         if(ind==s.size()){
//             if(isValid(a)){
//                 res.insert(a);
//             }
//             return;
//         }
//         //take or not
//         a.push_back(s[ind]);
//         check(s,ind+1,res,a);
//         a.pop_back();
//         check(s,ind+1,res,a);
//     }
//     vector<string> removeInvalidParentheses(string s) {
//         unordered_set<string>res;
//         string a="";
//         check(s,0,res,a);
//         vector<string>ans;
//         int len=0;
//         for(auto&i:res){
//             if(i.size()>=len){
//                 len=i.size();
//             }
//         }
//         for(auto&i:res){
//             if(i.size()==len){
//                 ans.push_back(i);
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:

    bool isValid(string &s) {
        int count = 0;

        for(char c : s) {

            if(c == '(') {
                count++;
            }
            else if(c == ')') {
                count--;

                if(count < 0)
                    return false;
            }
        }

        return count == 0;
    }

    void check(string &s, int ind,
               unordered_set<string>& res,
               string &a,
               int target) {

        // agar current string target se badi ho gayi
        if(a.size() > target)
            return;

        if(ind == s.size()) {

            if(a.size() == target && isValid(a)) {
                res.insert(a);
            }

            return;
        }

        // TAKE
        a.push_back(s[ind]);

        check(s, ind + 1, res, a, target);

        a.pop_back();

        // NOT TAKE
        check(s, ind + 1, res, a, target);
    }

    vector<string> removeInvalidParentheses(string s) {

        int balance = 0;
        int remove = 0;

        // minimum number of invalid brackets
        for(char c : s) {

            if(c == '(') {
                balance++;
            }
            else if(c == ')') {

                if(balance > 0) {
                    balance--;
                }
                else {
                    remove++;
                }
            }
        }

        remove += balance;

        // maximum possible valid length
        int target = s.size() - remove;

        unordered_set<string> res;

        string a = "";

        check(s, 0, res, a, target);

        vector<string> ans;

        for(auto &x : res) {
            ans.push_back(x);
        }

        return ans;
    }
};