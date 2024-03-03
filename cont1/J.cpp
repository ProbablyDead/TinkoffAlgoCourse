#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>

using namespace std;
void pre() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}

#define ll long long

ll sum(vector<vector<int> >& arr, int x1, int y1, int x2, int y2) {
  ll sum = 0;

  for (int i = x1; i <=x2; i++) {
    for (int j = y1; j <= y2; j++) {
      sum += arr[i][j];
    }
  }

  return sum;
}

ll diff(vector<vector<int> >& arr, bool ver, int s, int n, int m) {
  if (ver) {
    return sum(arr, 0, s, n-1, m-1) - sum(arr, 0, 0, n-1, s-1);
  } else {
    return sum(arr, s, 0, n-1, m-1) - sum(arr, 0, 0, s-1, m-1);
  }
}

pair<char, int> getSlice(int n, int m) {
  vector<vector<int> > arr;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      arr[i][j] = i * m + j + 1;
    }
  }

  int l = 0, r = m - 1;

  ll minn;

  while (r >= l) {
    int mid = l + (r - l)/2;

    ll d = diff(arr, true, mid, n , m);

    if (d == 0) {
      return make_pair('V', mid);
    }

    if (d > 0) {
      mid = r;
    } else {
      mid = l;
    }
  }

  l = 0, r = n - 1;

  while (r >= l) {
    int mid = l + (r - l)/2;

    ll d = diff(arr, true, mid, n , m);

    if (d == 0) {
      return make_pair('V', mid);
    }

    if (d > 0) {
      mid = r;
    } else {
      mid = l;
    }
  }

}

int main(int argc, char *argv[]) {
  pre();
  freopen("./input.txt", "r", stdin);

  int t;
  cin >> t;


  for (int _ = 0; _ < t; _++) {
    int n, m;
    cin >> n >> m;

    pair<char, int> res = getSlice(n, m);
    cout << res.first << " " << res.second + 1 << endl; 
  }

  return 0;
}
