#include <bits/stdc++.h>
#define ll long long
#define mn 10000007
using namespace std;
void koli()
{
  int n;
  cin >> n;
  string s;
  cin >> s;
  if (n == 1 || n == 2)
  {
    cout << "YES" << endl;
  }
  else
  {
    int cnt(0);
    for (int i = 0; i < n; i++)
    {
      if (s[i] != s[i + 1])
      {
        cnt = count(s.begin() + i + 1, s.end(), s[i]);
      }
      if (cnt >= 1)
      {
        cout << "NO" << endl;
        break;
      }
    }
    if (cnt == 0)
    {
      cout << "YES" << endl;
    }
  }
}
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    koli();
  }

  return 0;
}