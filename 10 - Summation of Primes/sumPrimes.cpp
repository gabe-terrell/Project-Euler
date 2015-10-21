#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<unsigned long> primes;
unsigned long x = 11;

// Check if n is prime. If it is, add to list
// Source: http://en.wikipedia.org/wiki/Primality_test
bool primeCheck (unsigned long n) {
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
 
    for (unsigned short i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    
    primes.push_back(n);
    return true;
}

// Returns the sum of all primes not greater than n
unsigned long sumPrimes (unsigned long n) {
    unsigned long sum;
    for (int i = 0; primes[i] <= n; i++) {
        sum += primes[i];
    }
    return sum;
}

int main() {
    // Initialize primes vector
    primes.push_back(2);
    primes.push_back(3);
    primes.push_back(5);
    primes.push_back(7);
    
    // Run test cases
    unsigned long t, n;
    cin >> t;
    
    while (t--) {
        cin >> n;
        while (primes.back() <= n) {
            primeCheck(x++);
        }
        cout << sumPrimes(n) << endl;
    }
    
    return 0;
}
