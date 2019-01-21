#include<bits/stdc++.h>
using namespace std;

class Date
{
public:
    string date;
    Date() {};
    Date(string date)
    {
        this->date=date;
    }
};
class Person
{
public:
    string name;
    Date date1;
    Person() {};

    Person(string name)
    {
        this->name=name;
    }
    Person(string name,string date)
    {
        this->name=name;
        date1.date=date;
    };

};

class Department
{
public:
    string dpt_name;
    Department() {};
    Department(string name)
    {
        dpt_name=name;
    }
};

class Student : public Person
{
public:
    string id;
    Department department;
    int totalsolve;
    string type;
    Student() {};
    Student(string name,string date,Department dpt_name,string id_no,int ts,string typeofcoder) : Person(name,date)
    {
        id=id_no;
        department=dpt_name;
        totalsolve=ts;
        type=typeofcoder;
    }
    view_student_info()
    {
        cout<<"Student name: "<<name<<endl;
        cout<<"Department: "<<department.dpt_name<<endl;
        cout<<"Student ID: "<<id<<endl;
        cout<<"Students Birthday: "<<date1.date<<endl;
        cout<<"Students total solve: "<<totalsolve<<endl;
        cout<<"Students type: "<<type<<endl;
    }
};

class Faculty : public Person
{
public:
    string designation;
    Department department;
    Faculty() {};
    Faculty(string designation,string name,Department department1):Person(name)
    {
        this->designation=designation;
        department=department1;
    }
    view_faculty()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Department: "<<department.dpt_name<<endl;
        cout<<"Designation: "<<designation<<endl;
    }

};

int main()
{
    Department dept("CSE");
    Student *student[10]=
    {
        new Student("Jony","20-10-1997",dept,"11608010",233,"NORMAL"),
        new Student("Nahid","25-8-1997",dept,"11608025",400,"NORMAL"),
        new Student("Ashiq","31-1-1997",dept,"11608035",300,"WORLD FINALIST"),
        new Student("Rakib","13-5-1998",dept,"11608003",200,"NORMAL"),
        new Student("Mahfuz","17-5-1996",dept,"11608016",275,"NORMAL")
    };
    cout<<"INFORMATION OF APPLICANTS: "<<endl<<endl;
    for(int i=0; i<4; i++)
    {
        cout<<"INFO OF STUDENT "<< i+1<<": "<<endl;
        student[i]->view_student_info();
        cout<<endl<<endl;
    }
    Faculty *faculty_member[2]=
    {
        new Faculty("Assistant Professor","Kamal Hossain Chowdhury",dept),
        new Faculty("Assistant Professor","Mahmudul Hasan",dept)
    };
    cout<<endl<<endl;
    cout<<"INFORMATION OF FACULTY: "<<endl<<endl;
    for(int i=0; i<2; i++){
        cout<<"INFO OF FACULTY "<<i+1<<": "<<endl;
        faculty_member[i]->view_faculty();
        cout<<endl;
    }
    int flag=0,index=-1;
    for(int i=0;i<4;i++)
    {
        if(student[i]->type == "WORLD FINALIST")
        {
            flag=1;
            index=i;
        }
    }
    cout<<endl<<endl;
    if(flag==1)
    {
        cout<<"INFO OF PROBLEM SETTER 1: "<<endl;
        student[index]->view_student_info();
        int in,mx=-1;
        for(int i=0;i<4;i++)
        {
            if(student[i]->type != "WORLD FINALIST" and student[i]->totalsolve>mx)
            {
                mx=student[i]->totalsolve;
                in=i;
            }
        }
        cout<<endl<<endl<<"INFO OF PROBLEM SETTER 2 WHOOSE PROBLEM MAY BE INCLUDED: "<<endl;
        student[in]->view_student_info();
    }
    else
    {
        int in,mx=-1;
        for(int i=0;i<4;i++)
        {
            if(student[i]->totalsolve>mx)
            {
                mx=student[i]->totalsolve;
                in=i;
            }
        }
        cout<<"INFO OF PROBLEM SETTER 1: "<<endl;
        student[in]->view_student_info();
        int mx1=-1,in1;
        for(int i=0;i<4;i++)
        {
            if(i!=in and student[i]->totalsolve>mx1)
            {
                in1=i;
                mx1=student[i]->totalsolve;
            }
        }
        cout<<endl<<endl<<"INFO OF PROBLEM SETTER 2 WHOOSE PROBLEM MAY BE INCLUDED: "<<endl;
        student[in1]->view_student_info();
    }
    return 0;
}

