/*
	This code was written by UOP_JPAC during ACES Precoders v8 2020
	pubuduudara7@gmail.com	imsuneth@gmail.com	pasan96tennakoon@gmail.com


*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    cin >> t;
    for(int k=0;k<t;++k){
        string s;
        cin >> s;
        string result;
        result += s[0];
        for(int i=1;i<s.length();++i)
        {
            if(s[i] > result[0]){
                result = result + s[i];
            }   
            else{
                result = s[i] + result;
            }
        }
        cout << result << endl;
    }
    return 0;
}