#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// http://sierra.nmsu.edu/morandi/CourseMaterials/GCD.html
long gcd (long x, long y) {
    if (x == y)
        return x;
    if (x > y)
        return gcd(x - y, y);
    else
        return gcd(x, y - x);
}

// http://sierra.nmsu.edu/morandi/CourseMaterials/LCM.html
long lcm (long x, long y) {
    return x * y / gcd(x, y);
}

// cumulative lcm from 1 to n
void cum_lcd (long n) {
    long m = 1;
    for (long i = 1; i <= n; i++) {
        m = lcm(i, m);
    }
    cout << m << endl;
}

int main() {
    int t;
    cin >> t;
    
    while (t) {
        long n;
        cin >> n;
        cum_lcd(n);
        t--;
    }
    
    return 0;
}
