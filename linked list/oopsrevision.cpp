#include<iostream>
using namespace std;
class student{         //user defined data type
public:
    int rollnu;
    string name;
    float marks;
    student(string name,int marks,int rollnu){
        this->marks=marks;
        this->name=name;
        this->rollnu=rollnu;
    }
};
void change(student *s){
    (*s).name="rawat";
}
int main(){
    student *s = new student("akhilesh",92.5,5);  //declaration with initialization
    // s.name="akhilesh rawat";
    // s.marks=92.6;
    // s.rollnu=5;

    cout<<s->name;
    //(*s).name="rawat";
    change(s);
    cout<<s->name;
    //cout<<s->name;
}