#include <iostream>
#include <stack>
#include <string>

using namespace std;
void pre() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
}

int main(int argc, char *argv[]) {
  pre();

  /* freopen("./input.txt", "r", stdin); */

  string str;
  stack<int> st;

  while(cin >> str) {
    if (str == "+" || str == "-" || str == "*") {
      int b = st.top();
      st.pop();

      int a = st.top();
      st.pop();

      int res;
      if (str == "+") {
        res = a + b;
      } else if (str == "-") {
        res = a - b;
      } else if (str == "*") {
        res = a * b;
      }

      st.push(res);
    } 
    else {
      st.push(stoi(str));
    }
  }

  cout << st.top() << endl;

  return 0;
}

