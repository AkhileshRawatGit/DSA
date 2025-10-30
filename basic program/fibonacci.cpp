#include<iostream>
using namespace std;
class A{
    public:
    int a;
    void getdata(int n){
        a=n;
    }
    void fibonacci(){
        int b,c=0,d=1;
        for(int i=0;i<a;i++){
            if(i<=1){
                b=i;
            }
            else{
                b=c+d;
                c=d;
                d=b;
            }
            cout<<b;
        }
    }

};
int main(){
    A p;
    p.getdata(5);
    p.fibonacci();
    return 0;


}