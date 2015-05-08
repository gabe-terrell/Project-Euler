#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

std::unordered_map<long,long> sequenceSize;

long collatzFunction (long n) {
  if (n % 2 == 0)
    return n/2;
  return 3*n + 1;
}

long calculateSequenceSize (long n) {
  if (sequenceSize.find(n) == sequenceSize.end())
    sequenceSize[n] = 1 + calculateSequenceSize(collatzFunction(n));
  return sequenceSize[n];
}

int main() {
  sequenceSize[1] = 1;
  long lim;
  int t;
  cin >> t;
  while (t--) {
    long max, n = 1;
    cin >> lim;
    while (n <= lim) {
      if (calculateSequenceSize(n) >= sequenceSize[max])
        max = n;
      n++;
    }
    cout << max << endl;
  }
}
