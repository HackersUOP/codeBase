#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, t;
    long sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) {
            cin >> t;
            if (i == j || i == n - j - 1)
                sum += t;
        }
    cout << sum;
    return 0;
}
