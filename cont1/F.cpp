#include <iostream>
#include <vector>

using namespace std;
void pre() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}

long long inversions = 0;

vector<int> merge(vector<int>& left, vector<int>& right) {
  vector<int> res(left.size() + right.size());

  for (int l = 0, r = 0, i = 0; i < res.size(); i++) {
    if (l == left.size()) {
      res[i] = right[r++];
      continue;
    }

    if (r == right.size()) {
      res[i] = left[l++];
      inversions++;
      continue;
    }

    if (left[l] > right[r] && r != right.size() - 1) {
      inversions += left.size() - l;
    }

    res[i] = left[l] < right[r] ? left[l++] : right[r++];
  }

  return res;
}

vector<int> myMergeSort(vector<int> arr) {
  if (arr.size() == 1) {
    return arr;
  }

  int mid = arr.size() / 2;
  vector<int> left = myMergeSort(vector<int>(arr.begin(), arr.end() - mid));
  vector<int> right = myMergeSort(vector<int>(arr.begin() + mid + (arr.size()%2 ? 1 : 0), arr.end()));

  return merge(left, right);
}

int main(int argc, char *argv[]) {
  pre();
  /* freopen("./input.txt", "r", stdin); */

  int n;

  cin >> n;
  vector<int> arr(n);

  for (auto& i : arr) {
    cin >> i;
  }

  arr = myMergeSort(arr);

  cout << inversions << endl;

  for (auto& i : arr) {
    cout << i << " "; 
  }

  cout << endl;

  return 0;
}
