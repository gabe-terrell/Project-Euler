#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solveDiophantine (int D) {
    //checks for perfect square
    double d_sqrt = sqrt(D);
    int i_sqrt = d_sqrt;
    if ( d_sqrt == i_sqrt ) {
        return -1;
    }
        
    int x = 2;
    while (true) {
        for (int y = x / 2 + 1; y > 0; y--) {
            int result = x*x - D*y*y;
            if (result < 1) {
                continue;
            }
            if (result == 1) {
                return x;
            }
            else {
                break;
            }
        }
        x++;
    }
}

int main() {
    int N;
    cin >> N;
    // Since 7 <= N, 5 5 is a suitable start since it's the solution for 7
    int x = 5;
    int x_sol = 9;
    
    for (int i = 6; i <= N; i++) {
        int sol = solveDiophantine(i);
        if (x_sol < sol) {
            x = i;
            x_sol = sol;
        }
    }
    
    cout << x << endl;
    
    return 0;
}
