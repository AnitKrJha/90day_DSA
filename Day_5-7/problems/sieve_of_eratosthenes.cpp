// Implement the Sieve of Eratosthenes algorithm to find all prime numbers up to
// a given limit. TC: O(n loglogn)

#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> &v) {
  for (auto &x : v) cout << x << " -> ";
  cout << '\n';
}

int main() {
  cout << "ENTER The limit:\n";
  int n;
  cin >> n;
  vector<bool> v(n + 1, false);
  v[0] = true;
  v[1] = true;
  for (int i = 2; i < n; i++) {
    if (!v[i]) {
      for (int k = i * 2; k <= n; k += i) {
        v[k] = true;
      }
    }
  }
  vector<int> primes;
  for (int i = 0; i < v.size(); i++) {
    if (!v[i]) primes.push_back(i);
  }

  printVector(primes);
}