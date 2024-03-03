#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;
void pre() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}

int main(int argc, char *argv[]) {
  pre();
  /* freopen("./input.txt", "r", stdin); */

  int n;
  cin >> n;

  vector<int> arr(n);

  cout << 1 << " ";

  int lastZeroPointer = n - 1;
  int countOf1s = 0;

  for (int _ = 0; _ < n; _++) {
    int v;
    cin >> v;

    v--;

    arr[v] = 1;

    if (v == lastZeroPointer) {
      for (int j = lastZeroPointer - 1; j >=0; j--) {
        if (arr[j] == 0) {
          lastZeroPointer = j;
          break;
        } else {
          countOf1s--;
        }
      }
    } else {
      countOf1s++;
    }

    cout << countOf1s + 1 << " ";

  }

  cout << endl;

  return 0;
}
