/*
        Copyright (C) 2020, Sathira Silva.
*/

#include <bits/stdc++.h>

using namespace std;

int oddPrime(int num) {
        int count = 0;
        if (num % 2 == 0)
            count++;
        while (num % 2 == 0)
            num /= 2;
        for (int i = 3; i <= sqrt(num); i++) {
            while (num % i == 0) {
                num /= i;
                if (i % 2 != 0) count++;
            }
        }
        if (num > 2)
            count++;
        return count;
    }

int towerBreakers(vector<int> arr) {
    int nim = 0;
    for (int i = 0; i < arr.size(); i++)
        nim ^= oddPrime(arr[i]);
    return (nim) ? 1 : 2;
}
