#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
void pre() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}

double eps = 1e-4;
double a, b, c, d;

double func(double x) {
  return a*x*x*x + b*x*x + c*x + d;
}

double doubleBinSearch() {
  double l = -2000, r = 2000;

  while (r - l > eps) {
    double mid = (l + r)/2;

    if (func(mid) < 0) {
      l = mid;
    } else {
      r = mid;
    }
  }

  return (l + r)/2;
}

int main(int argc, char *argv[]) {
  pre();
  freopen("./input.txt", "r", stdin);

  cin >> a >> b >> c >> d;

  if (a < 0) {
    a = -a;
    b = -b;
    c = -c;
    d = -d;
  }

  cout << fixed << setprecision(10) << doubleBinSearch() << endl;
}
