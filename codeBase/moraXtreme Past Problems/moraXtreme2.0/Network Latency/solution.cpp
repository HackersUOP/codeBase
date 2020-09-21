#include <bits/stdc++.h>

#define MAXN 10000

using namespace std;

vector<int> primes;
long ways[MAXN + 1];

void sieve() {
    bool prime[MAXN + 1];
    for (int i = 2; i * i <= MAXN; i++)
        if (!prime[i])
            for (int j = i * i; j <= MAXN; j += i)
                prime[j] = true;
    for (int i = 2; i <= MAXN; i++)
        if (!prime[i])
            primes.push_back(i);
}

int count(int n) 
{
    memset(ways, 0, sizeof(ways));
    ways[0] = 1;
    for(int i = 0; i < (int) primes.size(); i++)
        for(int j = primes[i]; j <= MAXN; j++) 
            ways[j] += ways[j - primes[i]];
    int left = 0, right = 80, res = -1;
    ways[0] = ways[1] = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (ways[mid] <= n)
            left = mid + 1;
        else {
            right = mid - 1;
            res = mid;
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    sieve();
    cout << count(n) << endl;
    // for (int i = 0; i <= MAXN; i++)
    //     cout << ways[i] << " ";
    return 0;
}
