#include<iostream>
using namespace std;
class student
{
    public:
    int id;
    char name[50];
    int age;
    char department[50];
    char graede[1];
};
void display()
{
    student s;
    cout<<"Enter student id:";
    cin>>s.id;
    cout<<"Enter student name:";
    cin>>s.name;
    cout<<"Enter student age:";
    cin>>s.age;
    cout<<"Enter student department:";
    cin>>s.department;
    cout<<"Enter student graede:";
    cin>>s.graede;
    cout<<"Student details:"<<endl;
    cout<<"-----------------"<<endl;
    
    cout<<"Student id:"<<s.id<<endl;
    cout<<"Student name:"<<s.name<<endl;
    cout<<"Student age:"<<s.age<<endl;
    cout<<"Student department:"<<s.department<<endl;
    cout<<"Student graede:"<<s.graede<<endl;
}
int main()
{
    cout<<"Welcome to student management system"<<endl;
    cout<<"Enter student details:"<<endl;
    display();
    return 0;
}


