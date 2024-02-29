#include <iostream>
#include <vector>

using namespace std;
int main(int argc, char *argv[]) {
  long n, k;

  cin >> n >> k;

  vector<long> arr(n), arrSuf(n), arrPref(n);

  for (long i = 0; i < n; i++) {
    long el;
    cin >> el;
    
    arr[i] = el;

    arrSuf[i] = i % (k) ? min(arr[i], arrSuf[i-1]) : arr[i];
  }

  arrPref[n-1] = arr[n-1];
  for (long i = n - 2; i >= 0; i--) {
    arrPref[i] = (i + 1) % (k) ? min(arr[i], arrPref[i+1]) : arr[i];
  }

  for (long i = 0; i <= n - k; i++) {
    cout << min(arrPref[i], arrSuf[i+k-1]) << " ";
  }

  cout << endl;

  return 0;
}

/*
7 3
1 3 2 4 5 3 1
*/
