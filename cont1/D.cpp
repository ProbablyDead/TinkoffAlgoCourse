#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
void pre() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}

double func(double x) {
  return x*x + sqrt(x + 1);
}

double eps = 1e-6;

double doubleBinSearch(double C) {
  double l = 0, r = C, mid = (l + r)/2;

  while (fabs(func(mid) - C) >= eps) {
    mid = (l + r)/2;

    if (func(mid) - C < 0) {
      l = mid;
    } else {
      r = mid;
    }

    /* cout << fabs(func(mid) - C) << endl; */
  }

  return mid;
}

int main(int argc, char *argv[]) {
  pre();
  /* freopen("./input.txt", "r", stdin); */

  double C;
  cin >> C;

  cout << fixed << setprecision(10) << doubleBinSearch(C) << endl;

  return 0;
}
