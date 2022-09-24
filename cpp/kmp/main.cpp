#include <iostream>
#include <string>
#include <vector>
using namespace std;

void get_next(string t, vector<int>& next) {
  int i = 0;
  int j = -1;

  next[0] = -1;
  while (i < t.size() - 1) {
    if (j == -1 || t[i] == t[j]) {
      next[++i] = ++j;
    } else {
      j = next[j];
    }
  }
}

int kmp_search(string& s, string& t) {
  int i = 0;
  int j = 0;
  vector<int> next(t.size());
  while (j == -1 || (i < s.size() && j < t.size())) {
    if (j == -1 || s[i] == t[j]) {
      i++;
      j++;
    } else {
      j = next[j];
    }
  }
  if (j == t.size()) {
    return i - j;
  } else {
    return -1;
  }
}

int main() {
  string s = "aaab";
  string t = "ab";
  cout << kmp_search(s, t) << endl;
  return 0;
}