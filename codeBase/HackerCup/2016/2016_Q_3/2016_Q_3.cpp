/*
Copyright Hackers' Club, University Of Peradeniya
Author : E/13/181 (Samurdhi Karunarathne)
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at *
http://www.apache.org/licenses/LICENSE-2.0 *
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
/*
Author: Samurdhi Karunarathne @ samurdhilbk
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll _mergeSort(ll arr[], ll arr1[], ll left, ll right, ll p);
ll merge(ll arr[], ll arr1[], ll left, ll mid, ll right, ll p);
ll mergeSort(ll arr[], ll arr1[], ll array_size, ll p) {
    return _mergeSort(arr, arr1, 0LL, array_size - 1, p);
}
ll _mergeSort(ll arr[], ll arr1[], ll left, ll right, ll p)
{
    ll mid, inv_count = 0LL;
    if (right > left) {
        mid = (right + left) / 2LL;
        inv_count = _mergeSort(arr, arr1, left, mid, p);
        inv_count += _mergeSort(arr, arr1, mid + 1LL, right, p);
        inv_count += merge(arr, arr1, left, mid + 1LL, right, p);
    }
    return inv_count;
}
ll merge(ll arr[], ll arr1[], ll left, ll mid, ll right, ll p)
{
    ll i, j, k;
    ll inv_count = 0LL;
    i = left;
    j = mid;
    while ((i <= mid - 1LL) && (j <= right))
    {
        if (arr[i] >= arr[j] + arr1[i] - p) {
            inv_count = inv_count + (mid - i);
            j++;
        }
        else {
            i++;
        }
    }
    return inv_count;
}
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        ll n, p;
        cin >> n >> p;
        ll arr[n];
        ll arr1[n];
        ll num = 0LL;
        ll sm = 0LL;
        for (ll j = 0; j < n; j++) {
            ll tmp;
            cin >> tmp;
            if (tmp <= p) num++;
            arr1[j] = tmp;
            sm += tmp;
            arr[j] = sm;
        }
        printf("Case #%d: %lld\n", i + 1, mergeSort(arr, arr1, n, p) + num);
    }
    return 0;
}
