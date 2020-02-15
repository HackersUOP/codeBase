/*
    This code was written by UOP_JPAC during ACES Precoders v8 2020
    pubuduudara7@gmail.com  imsuneth@gmail.com  pasan96tennakoon@gmail.com
*/
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

void select(vector<float> s, vector<float> f) {
    vector<pair<float, float>> ans;

    priority_queue<pair<float, float>, vector<pair<float, float>>, greater<pair<float, float>>> p;

    for (int i = 0; i < s.size(); i++) {
        p.push(make_pair(f[i], s[i]));
    }

    auto it = p.top();
    float start = it.second;
    float end = it.first;
    p.pop();
    ans.push_back(make_pair(start, end));

    while (!p.empty()) {
        auto itr = p.top();
        p.pop();
        if (itr.second >= end) {
            start = itr.second;
            end = itr.first;
            ans.push_back(make_pair(start, end));
        }
    }
    cout << ans.size() << endl;

}

int main() {
    int n;
    cin >> n;
    char x;
    float a, b;


    string line;

    vector<float> s;
    vector<float> f;

    int j = 0;
    for (int i = 0; i < n; i++) {
        string yes, start, end;
        cin >> yes >> start >> end;
        if (yes[0] == 'Y') {
            replace(start.begin(), start.end(), ':', '.');
            replace(end.begin(), end.end(), ':', '.');


            string tok;
            vector<string> internal1, internal2;
            stringstream ss(start);
            stringstream ee(end);
            while(getline(ss, tok, '.')) {
                internal1.push_back(tok);
            }

            while(getline(ee, tok, '.')) {
                internal2.push_back(tok);
            }

            float sss = stof(internal1[0])*60 + stof(internal1[1]);
            float enn = stof(internal2[0])*60 + stof(internal2[1]);

            s.push_back(sss);
            f.push_back(enn);
            j++;
        }


    }

    select(s, f);

    return 0;
} 