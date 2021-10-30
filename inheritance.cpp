#include<iostream>

using namespace std;

class Person
{
    string name,address;
    float age;
    int phone;

public:
    void getData()
    {
        cout<<"Enter the person name : "<<endl;
        cin>>name;
        cout<<"Enter person age : "<<endl;
        cin>>age;
        cout<<"Enter the person address : "<<endl;
        cin>>address;
        cout<<"Enter the Person's phone number : "<<endl;
        cin>>phone;
    }

    void display()
    {
        cout<<"Output....."<<endl;
        cout<<"Name : "<<name<<endl;
        cout<<"Age : "<<age<<endl;
        cout<<"Address : "<<address<<endl;
        cout<<"Phone : "<<phone<<endl;

    }


};

class Account
{
protected:

    float pm;
    float in;
    float ac;

public:
    void getAc()
    {
        ac=50000;
        pm=2000*12;
        in=0.5;
    }

};

class Bank:public Person,public Account
{
    float s;
 public:
     int cal()
     {

         s=(24000*5*0.25)/100;
         cout<<"Extra amount he/she is getting annually : "<<s<<endl;
     }

};

int main()
{
    Bank obj;

    obj.getData();
    obj.display();
    obj.cal();



    return 0;
}

