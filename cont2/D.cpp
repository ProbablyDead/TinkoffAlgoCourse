#include <iostream>
#include <vector>

using namespace std;
void pre() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
}

int checkStack(vector<int>& st) {
  int on_top = st.back(), c = 0;

  for (int j = st.size() - 1; j >= 0; j--) {
    if (st[j] == on_top) { c++; }
    else { break; }
  }

  if (c >= 3) {
    for (int j = 0; j < c; j++) {
      st.pop_back();
    }
    return c;
  }
  return 0; 
}

int main(int argc, char *argv[]) {
  pre();

  /* freopen("./input.txt", "r", stdin); */

  int n;
  cin >> n;

  vector<int> st;

  int result = 0;
  for (int i = 0, ball; i < n; i++) {
    cin >> ball;

    if (st.empty() || st.back() == ball) {
      st.push_back(ball);

      if (i != n - 1) { continue; }
    }

    result += checkStack(st);

    st.push_back(ball);
  }

  cout << result << endl;
  return 0;
}

