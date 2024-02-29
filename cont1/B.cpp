#include <iostream>
#include <vector>

using namespace std;
void pre() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}

int closestModulus(vector<int>& arr, int value) {
  int l = 0, r = arr.size()-1;

  while (r >= l) {
    int mid = (l + r)/2; 

    if (arr[mid] == value) {
      return arr[mid];
    }

    if (arr[mid] < value) {
      l = mid + 1;
    }
    else {
      r = mid - 1; 
    }
  }
  
  if (r < 0) {
    return arr[l];
  }

  if (l > arr.size()-1) {
    return arr[r];
  }


  int r_v = abs(arr[r] - value); 
  int l_v = abs(arr[l] - value);
  if (r_v == l_v) {
    return min(arr[r], arr[l]);
  } else {
    return l_v < r_v ? arr[l] : arr[r];
  }
}

int main(int argc, char *argv[]) {
  pre();
  /* freopen("./input.txt", "r", stdin); */

  int n, k;
  cin >> n >> k;

  vector<int> arr(n);
  for (auto& a : arr) {
    cin >> a;
  }

  for (int i = 0, v; i < k; i++) {
    cin >> v;
    cout << closestModulus(arr, v) << endl;
  }

  return 0;
}
