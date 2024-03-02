#include <iostream>
#include <vector>

using namespace std;
void pre() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}

int n, c = 0;

void myQsort(vector<int>& a, int left, int right)
{
  if (right <= left)
    return;

  int q = a[(left + right) / 2];
  int i = left;
  int j = right;

  while (i <= j) {
    while (a[i] < q) {
      ++i;
      c++;
    }
    while (q < a[j]) {
      --j;
      c++;
    }
    if (i <= j) {
      swap(a[i], a[j]);
      ++i;
      --j;
    }
  }

  myQsort(a, left, j);
  myQsort(a, i, right);
}

void anti_qsort(vector<int>& arr, int l, int r) {
  for (int i = 0; i < n; i++) {
    arr[i] = i+1;
    swap(arr[i], arr[i/2]);
  }
}

/* int checkMax(int l) { */
/*   int itemsLength = l; */
/*   int items [itemsLength]; */

/*   for (int i = 0 ; i < itemsLength ; i++) { items[i] = i + 1; } */

/*   int maxi = 0; */

/*   vector<int> v; */
/*   for (int i=0; i!=itemsLength; ++i) v.push_back(items[i]); */ 

/*   while (next_permutation(v.begin(), v.end() ) ) */ 
/*   { */ 
/*       vector<int> t = v; */
/*       myQsort(t, 0, t.size() - 1); */

/*       maxi = max(c, maxi); */

/*       c = 0; */
/*   } */

/*   return maxi; */
/* } */

int main(int argc, char *argv[]) {
  pre();
  freopen("./input.txt", "r", stdin);

  cin >> n;
  vector<int> arr(n);

  anti_qsort(arr, 0, n - 1);

  for (int i : arr) {
    cout << i << " ";
  }

  // CHECK! DEL
  /* myQsort(arr, 0, arr.size()-1); */
  /* cout << " " << c << endl; */
  /* c = 0; */
  /* cout << checkMax(arr.size()) << endl; */
  // CHECK! DEL

  return 0;
}
