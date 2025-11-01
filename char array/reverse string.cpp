#include<iostream>
using namespace std;
void reverse(char ch[],int len){
    int s=0;
    int e=len-1;
    while(s<e){
        swap(ch[s++],ch[e--]);
    }
}
int length(char ch[]){
    int count=0;
    for(int i=0;ch[i]!='\0';i++){
        count++;
    }
    return count;
}
char mazoccCharacter(string s){
    int arr[26]={0};
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        int number=0;
        number=ch-'a';
        arr[number]++;
    }
    int maxi=-1,ans=0;
    for(int i=0;i<26;i++){
        if(maxi<arr[i]){
            ans=i;
            maxi=arr[i];
        }
    }
    return 'a'+ans;
}
int main(){
    char ch[20];
    cout<<"Enter your name: ";
    cin>>ch;
    cout<<"your name is : "<<ch;
    cout<<length(ch);
    int len=length(ch);
    reverse(ch,len);
    cout<<ch;
    
    return 0;
}