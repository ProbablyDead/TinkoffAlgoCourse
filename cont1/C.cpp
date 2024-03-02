#include <iostream>

using namespace std;
void pre() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}

int n;

void guessNumber() {
  int l = 1, r = n + 1;

  while (r - l > 1) {
    int mid = (l + r) / 2;

    cout << mid << endl;
    fflush(stdout);

    string ans;
    cin >> ans;

    if (ans == "<") {
      r = mid;
    } else {
      l = mid;
    }
  }

  cout << "! " << l << endl;
}

int main(int argc, char *argv[]) {
  pre();

  cin >> n;

  guessNumber();

  return 0;
}
