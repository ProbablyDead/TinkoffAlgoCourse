#include <iostream>
#include <vector>

using namespace std;
void pre() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}

int main(int argc, char *argv[]) {
  pre();

  freopen("./input.txt", "r", stdin);

  int n, movesCount = 0;

  cin >> n;

  vector<int> arr(n);

  for (auto &i : arr) {
    cin >> i;
  }



  return 0;
}
