#include <iostream>
using namespace std;

struct myStruct
{
  int age;
  string name;
};

int main()
{
  myStruct S1 = {20, "Vishek Patel"};
  cout << "Your name is : " << S1.name << " and you're " << S1.age << " year's old." << endl;

  return 0;
}
