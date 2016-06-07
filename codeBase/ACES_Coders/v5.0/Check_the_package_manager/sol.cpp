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

#include <bits/stdc++.h>
using namespace std;

map<char, vector<char> > graph;
vector<bool> visited;
bool found;

void dfs(char c, char d) {
    if (found) return;
    if (c == d) {
        found = true;
        return;
    }
    if (visited[c - 'A']) return;
    visited[c - 'A'] = true;
    for (int i = 0; i < graph[c].size(); i++) dfs(graph[c][i], d);
}

bool can(char s, char d) {
    found = false;
    dfs(s, d);
    for (int i = 0; i < visited.size(); i++) visited[i] = false;
    return found;
}

int main() {
    visited.resize(27, false);
    string S;
    int d;
    getline(cin, S);
    stringstream ss(S);
    ss >> d;
    for (int i = 0; i < d; i++) {
        getline(cin, S);
        char a = S[0], b = S[2];
        if (graph.find(b) != graph.end()) graph[b].push_back(a);
        else {
            vector<char> temp;
            temp.push_back(a);
            graph[b] = temp;
        }
    }
    string s1;
    getline(cin, s1);
    string s;
    for (int i = 0; i < s1.size(); i++) if (s1[i] != ' ') {
            s.push_back(s1[i]);
        }

    for (int i = 1; i < s.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (can(s[i], s[j])) {
                cout << "wrong" << endl;
                return 0;
            }
        }
    }

    cout << "correct" << endl;
    return 0;
}
