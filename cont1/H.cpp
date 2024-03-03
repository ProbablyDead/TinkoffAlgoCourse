#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
void pre() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}

int n;

string getPalindrome(char str []) {
  int dict [26] = { 0 }; 

  for (int i = 0; i < n; i++) {
    dict[int(str[i] - 65)]++;
  }

  string begin;
  char mid = '\0';

  for (int i = 0; i < 26; i++) {
    if (dict[i]%2 && !mid) {
      mid = i + 65;
      dict[i]--;
    }

    if (dict[i] == 0) { continue; }

    for (int j = 0; j < dict[i]/2; j++) {
      begin += i + 65;
    }
  }

  string back = begin;

  reverse(back.begin(), back.end());

  if (mid) {
    begin += mid;
  }

  return begin + back;
}

int main(int argc, char *argv[]) {
  pre();
  /* freopen("./input.txt", "r", stdin); */

  cin >> n;

  char str [n];

  for (char& i : str) {
    cin >> i;
  }

  cout << getPalindrome(str) << endl;

  return 0;
}
