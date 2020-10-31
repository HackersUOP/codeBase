/*
    Copyright (C) 2020, Sathira Silva.
    
    Approach: The idea is to store the number of subsets having gcd equal to some x for all possible x's using dynamic programming. Then we can respond to the queries in O(1).
              Note that the maximum gcd a sequence can have is the maximum value of that sequence. Also note that the gcd of the sequence <n, 2n, 3n, ...> is n. So, to find the
              number of subsets with gcd x all we have to do is counting the number of occurrences of all possible multiples of x in the array. If the count is c, the number of
              valid subsets are 2^c - 1 - {number of subsets with gcd = y (> x)}. We deduct 1 to exclude the empty subset. Since we count the occurrences of multiples of x,
              we also include the subsets which doesn't include x but it's other multiples. So we have to deduct those number of subsets too.
*/

#include <bits/stdc++.h>

#define mod 1000000007

using namespace std;

typedef long long ll;

ll modpow(ll x, ll y) {
    ll res = 1;
    x %= mod;
    if (x == 0) return 0;
    while (y) {
        if (y & 1)
            res = (res * x) % mod;
        y >>= 1;
        x = (x * x) % mod;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    ll balls[n], freq[10001], dp[10001], maxn = INT_MIN;
    memset(freq, 0, sizeof(freq));
    for (int i = 0; i < n; i++) {
        cin >> balls[i];
        // Count the frequencies of the numbers
        freq[balls[i]]++;
        // The maximum possible gcd is the maximum number in the array
        maxn = max(maxn, balls[i]);
    }
    memset(dp, 0, sizeof(dp));
    for (ll x = maxn; x >= 1; x--) {
        ll c = 0;
        // Check all multiples of x
        for (ll y = x; y <= maxn; y+=x) {
            // Count number of occurrences of the current multiple of x
            c += freq[y];
            // Subtract the number of subsets with gcd = y (> x) since the gcd of subsets that doesn't include x but multiples of x is not x
            if (y > x)
                dp[x] = (dp[x] - dp[y] + mod) % mod;
        }
        // The number of subsets with gcd = x is dp[x] (we have already subtracted the subsets that includes multiples of x except x) + 2^c - 1 (excluding the empty set)
        dp[x] = (dp[x] + modpow(2, c) - 1 + mod) % mod;
    }
    int q;
    cin >> q;
    for (int _ = 0; _ < q; _++) {
        int x;
        cin >> x;
        // Answer the queries in O(1) complexity
        cout << dp[x] << endl;
    }
}
