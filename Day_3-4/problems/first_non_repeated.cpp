// The problem is to find the first NON repeated character without using extre
// space.
//
// For ex: GeeksForGeeks 'F' is first non repeating character.

#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
  string s;
  cin >> s;

  unordered_map<char, int> mp; // size always less than ""256"".
  for (auto &x : s)
    mp[x]++;

  for (auto &x : s)
    if (mp[x] == 1) {
      cout << x << '\n';
      break;
    }
  return 0;
}
