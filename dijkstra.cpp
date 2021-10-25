#include<bits/stdc++.h>

using namespace std;
typedef long long int ll; //g++ ll.cpp -o ll.exe
typedef long double ld;
typedef pair < ll, ll > iii; //all elements to 0
const ll mod = 1e9 + 7;

ll n, m;

struct nodes {
  ll x;
  ll y;
  ll z;
};

vector < vector < iii >> v;
vector < nodes > w;

void dijkstra(int sc, int n, int m) {

  vector < ll > dist(n + 1, 1e18);
  bool vis[n + 1];

  memset(vis, 0, sizeof(vis));

  priority_queue < iii > q;

  dist[sc] = 0;
  q.push({
    0,
    sc
  });

  while (!q.empty()) {
    iii temp;
    temp = q.top();
    q.pop();

    if (vis[temp.second])
      continue;
    vis[temp.second] = 1;

    for (auto u: v[temp.second]) {
      if (dist[u.second] > dist[temp.second] - u.first) {
        dist[u.second] = dist[temp.second] - u.first;
        q.push({
          -dist[u.second],
          u.second
        });

      }

    }

  }

  for (int i = 1; i <= n; i++) {
    cout << "dist from sc " << sc << " of node " << i << " is " << dist[i] << endl;
  }
  cout << endl;

}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  //cin>>n>>m;

  n = 6;
  m = 6;

  v.resize(n + 1);
  w.resize(m + 1);

  ll a, b, c, i;
  // cin>>a>>b>>c;

  i = 1;
  a = 1;
  b = 2;
  c = 2;
  v[a].push_back({
    -c,
    b
  });
  v[b].push_back({
    -c,
    a
  });
  w[i].x = a;
  w[i].y = b;
  w[i].z = c;

  i = 2;
  a = 2;
  b = 4;
  c = 7;
  v[a].push_back({
    -c,
    b
  });
  v[b].push_back({
    -c,
    a
  });
  w[i].x = a;
  w[i].y = b;
  w[i].z = c;

  i = 3;
  a = 4;
  b = 5;
  c = 1;
  v[a].push_back({
    -c,
    b
  });
  v[b].push_back({
    -c,
    a
  });
  w[i].x = a;
  w[i].y = b;
  w[i].z = c;

  i = 4;
  a = 5;
  b = 3;
  c = 9;
  v[a].push_back({
    -c,
    b
  });
  v[b].push_back({
    -c,
    a
  });
  w[i].x = a;
  w[i].y = b;
  w[i].z = c;

  i = 5;
  a = 3;
  b = 1;
  c = 8;
  v[a].push_back({
    -c,
    b
  });
  v[b].push_back({
    -c,
    a
  });
  w[i].x = a;
  w[i].y = b;
  w[i].z = c;

  i = 6;
  a = 3;
  b = 6;
  c = 7;
  v[a].push_back({
    -c,
    b
  });
  v[b].push_back({
    -c,
    a
  });
  w[i].x = a;
  w[i].y = b;
  w[i].z = c;

  dijkstra(1, 6, 6);

  return 0;
}
