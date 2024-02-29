#include <iostream>
#include <vector>

using namespace std;
void pre() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}

bool binSearch(vector<int>& arr, int value) {
  int l = 0, r = arr.size() - 1;

  while (r >= l) {
    int mid = (l + r)/2; 

    if (arr[mid] == value) {
      return true;
    }

    if (arr[mid] < value) {
      l = mid + 1;
    }
    else {
      r = mid - 1; 
    }
  }

  return false;
}

int main(int argc, char *argv[]) {
  pre();

  /* freopen("./input.txt", "r", stdin); */

  int n, k;

  cin >> n >> k;

  vector<int> arr(n);

  for (auto &i : arr) {
    cin >> i;
  }

  for (int i = 0, v; i < k; i++) {
    cin >> v;
    cout << (binSearch(arr, v) ? "YES" : "NO") << endl;
  }

  return 0;
}
