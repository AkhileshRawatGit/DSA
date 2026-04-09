#include<iostream>
#include<vector>
using namespace std;
vector<int>v(10,-1);
int front=-1;
int rear=-1;

void push(int val){
    if(front==-1 && rear==-1){
        front++;
        rear++;
    }
    if(rear>v.size()-1){
        cout<<"overflow";
    }
    v[rear++]=val;
    cout<<"push";
}
int pop(){
    int val=-1;
    if(front>rear ||(front==-1 && rear==-1)){
        cout<<"underflow";
    }
    else{
        val=v[front++];
    }
    return val;
}
void display(){
    for(int i=front;i<rear;i++){
        cout<<v[i]<<" ";
    }
}
int main(){
    cout<<v.size();
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    cout<<"->";
    display();
    cout<<"->";
    cout<<pop()<<endl;
    display();

}