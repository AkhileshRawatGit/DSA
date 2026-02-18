// #include<iostream>
// #include<vector>
// using namespace std;
// int main(){
//     vector<pair<int,int>>v;
//     v.push_back({2,3});
//     for(auto i:v){
//         cout<<i.first<<endl;
//         cout<<i.second;
//     }
// }

#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    cin>>s;
    char ch;
    cin>>ch;
    int ind=-1;
    int val=INT8_MIN;
    for(int i=0;i<s.size();i++){
        if(s[i]==ch&&i<s.size()){
            int ch=s[i+1]-'0';
            if(ch>val){
                val=ch;
                ind=i;
            }
        }
    }
    string ans="";
    for(int i=0;i<s.size();i++){
        if(i==ind){
            continue;
        }
        else{
            ans+=s[i];
        }
    }
    cout<<ans;
    return 0;
}
