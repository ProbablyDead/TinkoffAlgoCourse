#include <iostream>
#include <utility>
#include <vector>

using namespace std;
int main(int argc, char *argv[]) {
  int n;
  cin >> n;

  vector<pair<long, long> > arr;

  for (int _ = 0; _ < n; _++) {
    long action;
    cin >> action;

    switch (action) {
      case 1:
        long val;
        cin >> val;

        arr.push_back(make_pair(val, 
              arr.empty() ? val : min(val, arr.back().second)));
        break;
      case 2:
        arr.pop_back();
        break;
      case 3:
        cout << arr.back().second << endl;
        break;
    }
  }
}

/*
8
1 2
1 3
1 -3
3
2
3
2
3
*/
