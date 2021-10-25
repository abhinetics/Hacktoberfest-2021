#include <bits/stdc++.h>
using namespace std;

#define gc getchar_unlocked
#define fo(u, k, n) for (u = k; u <= n; u++)
#define pb push_back
#define mp make_pair
#define ll long long
#define endl '\n'
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define allr(c) c.rbegin(), c.rend()
#define mem(x) memset(x, 0, sizeof(x))
#define PI 3.1415926535897932384626

typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<pll> vpll;
typedef vector<vl> vvl;
typedef map<ll, ll> ml;
typedef map<ll, bool> mlb;

const int MOD = 1000000007;

int main()
{
    long long t;
    cin >> t;

    while (t--)
    {
        long long n;
        cin >> n;

        vector<long long> vc;
        for (long long i = 0; i < n; i++)
        {
            long long num;
            cin >> num;
            vc.push_back(num);
        }

        sort(vc.begin(), vc.end());

        if (vc[n - 1] == 0)
        {
            cout << "0" << endl;
            continue;
        }

        else
        {
            long long l = 0, r = n - 1;
            long long product = 1;

            product *= vc[r];
            r--;

            for (long long itr = 1; itr <= 2; itr++)
            {

                long long left_product = vc[l] * vc[l + 1];
                long long right_product = vc[r] * vc[r - 1];

                if (left_product > right_product)
                {
                    product *= left_product;
                    l += 2;
                }
                else
                {
                    product *= right_product;
                    r -= 2;
                }
            }

            cout << product << endl;
        }
    }
}