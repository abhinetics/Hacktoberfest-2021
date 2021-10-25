#include <iostream>
using namespace std;

class Array
{
  int a[30];
  int size;

public:
  void Input();
  void Dup();
  void AsDe();

} A;

void Array ::Input()
{
  cout << "How many elements??" << endl;
  cin >> size;
  cout << "Enter elements of array" << endl;
  for (int i = 0; i < size; i++)
    cin >> a[i];
}

void Array ::Dup()
{
  for (int i = 0; i < size; i++)
    for (int j = i + 1; j < size;)
    {
      if (a[i] == a[j])
      {
        for (int k = j; k < size - 1; ++k)
          a[k] = a[k + 1];

        --size;
      }
      else
        ++j;
    }
  cout << "\n";
  for (int i = 0; i < size; ++i)
    cout << a[i] << " ";
}

void Array ::AsDe()
{
  bool isAs = true, isDe = true;

  for (int i = 1; i < size; i++)
  {
    if (a[i] < a[i - 1])
      isAs = false;

    if (a[i] > a[i - 1])
      isDe = false;
  }

  if (isAs && isDe)
    cout << "\n Array is in both Ascending and Descending Order";
  else if (isAs)
    cout << "\n Array is in Ascending Order";
  else if (isDe)
    cout << "\n Array is in Descending Order";
  else
    cout << "\n Array is in neither Ascending nor Descending Order";
}

void Menu()
{
  char choice;

  cout << "\n\n Menu of Operations on Array ";
  cout << "\n 1. Remove the Duplicate Elements";
  cout << "\n 2. Check for Ascending & Descending ";
  cout << "\n 3. Exit the Program";
  cout << "\n Your Choice: ";
  cin >> choice;

  switch (choice)
  {

  case '1':
  {
    A.Input();
    A.Dup();
  }
  break;

  case '2':
  {
    A.Input();
    A.AsDe();
  }
  break;

  case '3':
  {
    exit(1);
  }
  break;

  default:
    cout << "\n Wrong Choice! Please Enter Again!!";
    break;
  }
}

int main()
{
  while (1)
    Menu();
}
