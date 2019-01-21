#include<bits/stdc++.h>
using namespace std;

class Person
{
private:
    string name;
    string DOB;
public:
    Person() {}
    Person(string name)
    {
        this->name = name;
    }

    Person(string name,string DOB)
    {
        this->name = name;
        this->DOB = DOB;
    }
    setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return name;
    }
    string getDOB()
    {
        return DOB;
    }
};

class Student : public Person
{
private:
    int id;
public:
    Student() {}
    Student(string name) : Person(name) {}
    Student(string name, int id) : Person(name)
    {
        this->id = id;
    }
    int getId()
    {
        return id;
    }
    setId(int id)
    {
        this->id = id;
    }
};

class CseSocietyMember : public Student
{
private:
    int marks = 0;
public:
    CseSocietyMember() {}
    CseSocietyMember(string name):Student(name) {}
    CseSocietyMember(string name,int id):Student(name,id) {}
    void operator+(int n)
    {
        marks+=n;
    }
    int getMarks()
    {
        return marks;
    }
    int setMark(int n)
    {
        marks+=n;
    }
};

class Teacher : public Person
{
public:
    Teacher() {}
    Teacher(string name):Person(name) {}
};

class cseDept
{
private:
    int studentNum = 500;
    int classRoom = 2;
    int lab = 2;
public:
    vector<string> randomSelection (CseSocietyMember* cseSocietyMember)
    {

        vector<string>name;
        vector<int> n = randomNumGenerator(1, 10, 1);

        for(int i=0; i<5; i++)
        {
            cseSocietyMember+=(n[i]);
            name.push_back(cseSocietyMember->getName());
            cseSocietyMember-=(n[i]);
        }
        return name;
    }

    vector<int> randomNumGenerator(int lower, int upper,int count)
    {
        vector<int> myVector;
        srand((unsigned)time(NULL));

        while(myVector.size() < 5)
        {
            int b = rand() % 10;
            if ( !(find(myVector.begin(), myVector.end(), b) != myVector.end()))
            {
                myVector.push_back(b);
            }
        }
        return myVector;
    }

    void conductSurvey(CseSocietyMember* cseSocietyMember)
    {
        Student student;
        string name, isFinished;
        int n,id;
        cout<<"At first,Students will give their marks.Then honorable Teachers will give their marks"<<endl;
        while(true)
        {
            cout<<"Please enter your name: ";
            cin>>name;
            student.setName(name);
            cout<<"Please enter your ID: ";
            cin>>id;
            student.setId(id);
            cout<<"\nHello, "<<student.getName()<<endl;
            for(int i=0; i<5; i++,cseSocietyMember++)
            {
                //int n;
                cout<<"How much point do you want to give to "<<cseSocietyMember->getName()<<" (between 1 to 5): ";
                cin>>n;
                while(n<1 or n>5)
                {
                    cout<<"Invalid point.\nPlease give points between 1 to 5: ";
                    cin>>n;
                }
                cout<<n<<endl;

                cseSocietyMember->setMark(n);
                cout<<"You have given "<<cseSocietyMember->getMarks()<<" points to "<<cseSocietyMember->getName()<<endl<<endl;

            }
            cseSocietyMember -=5;
            cout<<"\n\nWell done, "<<student.getName()<<endl;
            cout<<"You've successfully completed survey"<<endl;
            cout<<"-------------------------------------------"<<endl<<endl;

            cout<<"If all the students have finished with their markings, type 'd' and\nThen honorable Teachers will give their marks"<<endl;
            cout<<"Otherwise type 'c' to continue as a student"<<endl;
            cin>>isFinished;
            if(isFinished == "c")
                cout<<"Now next student will give mark."<<endl;
            else break;

        }

        Teacher teacher;
        cout<<"Now honorable Teachers will give their marks"<<endl;
        while(true)
        {
            cout<<"Please enter your name: ";
            cin>>name;
            teacher.setName(name);

            cout<<"\nHello, "<<teacher.getName()<<" sir"<<endl;
            for(int i=0; i<5; i++,cseSocietyMember++)
            {

                cout<<"How much point do you want to give to "<<cseSocietyMember->getName()<<" (between 1 to 5): ";
                cin>>n;
                while(n<1 or n>5)
                {
                    cout<<"Invalid point.\nPlease give points between 1 to 5: ";
                    cin>>n;
                }
                cout<<n<<endl;

                cseSocietyMember->setMark(n);
                cout<<"You have given "<<cseSocietyMember->getMarks()<<" points to "<<cseSocietyMember->getName()<<endl<<endl;
            }
            cseSocietyMember -=5;
            cout<<"\n\nWell done, "<<student.getName() <<" sir"<<endl;
            cout<<"You've successfully completed survey"<<endl;
            cout<<"-------------------------------------------"<<endl<<endl;

            cout<<"If all Teachers have finished with their markings, Then please type 'd' "<<endl;
            cout<<"Otherwise type 'c' to continue"<<endl;
            cin>>isFinished;
            if(isFinished == "d")
                break;
            else continue;
        }
    }

    void displayResult(CseSocietyMember* cseSocietyMember)
    {
        cout<<"\n\nHere is the result of the survey."<<endl;
        cout<<"Name\t\t\tPoints"<<endl;
        int mx =-1,index = -1;
        for(int i=0; i<5; i++,cseSocietyMember++)
        {
            cout<<cseSocietyMember->getName()<<"\t\t\t"<<cseSocietyMember->getMarks()<<endl;
            if(mx < cseSocietyMember->getMarks())
            {
                mx = cseSocietyMember->getMarks();
                index = i;
            }
        }
        cseSocietyMember -=5;
        cout<<"-----------------------------------------------"<<endl;
        if(mx !=-1) cseSocietyMember += index;
        cout<<"\n\nThe best CSE Society Member is "<<cseSocietyMember->getName()<<endl;
    }

    void displayMembers(CseSocietyMember* cseSocietyMember,int n)
    {

        for(int i = 0;i<n;i++)
        {
            cout<<cseSocietyMember->getName()<<endl;
            cseSocietyMember++;
        }
    }
};

int main()
{
    cseDept cseDept;

    CseSocietyMember cseSocietyMember[10]=
    {
        CseSocietyMember("Ashik",11708001),
        CseSocietyMember("Rakibul",11708002),
        CseSocietyMember("Jony",11708003),
        CseSocietyMember("Imran",11708004),
        CseSocietyMember("Indrojit",11708005),
        CseSocietyMember("Nayem",11708006),
        CseSocietyMember("Polash",11708008),
        CseSocietyMember("Mahfuz",11708011),
        CseSocietyMember("Sabbir",11708014),
        CseSocietyMember("saiful",11708015)
    };

    cout<<"List of all cse society members:"<<endl;
    cout<<"---------------------------------"<<endl;
    cseDept.displayMembers(cseSocietyMember,10);

    cout<<"\nThe 5 randomly selected student, they will be voted:\n";
    cout<<"-------------------------------------------------------"<<endl;


    vector<string> namesOfRandomlySelectedMembers = cseDept.randomSelection(cseSocietyMember);

    CseSocietyMember selectedCseSocietyMember[5];
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(cseSocietyMember[j].getName() == namesOfRandomlySelectedMembers[i])
            {
                selectedCseSocietyMember[i] = cseSocietyMember[j];

            }
        }
    }

    cseDept.displayMembers(selectedCseSocietyMember,5);
    cout<<endl<<endl;
    cseDept.conductSurvey(selectedCseSocietyMember);
    cseDept.displayResult(selectedCseSocietyMember);

    return 0;
}
