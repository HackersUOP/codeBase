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
#include <stdio.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        vector<vector<char> > vecchar;
        vector<vector<int> > vecnum;
        bool all_equal = true;
        for (int j = 0; j < n; j++) {
            vector<char> temp_vec;
            vector<int> temp_vec1;
            vecchar.push_back(temp_vec);
            vecnum.push_back(temp_vec1);
            string s;
            cin >> s;
            unsigned int curr_ind = 0;
            vecchar[j].push_back(s[curr_ind]);
            while (curr_ind < s.size()) {
                int tmp = 1;
                while (s[curr_ind] == s[curr_ind + 1]) {
                    tmp++;
                    curr_ind++;
                }
                vecnum[j].push_back(tmp);
                curr_ind++;
                vecchar[j].push_back(s[curr_ind]);
            }
            if (j > 0) all_equal = all_equal && (vecchar[j] == vecchar[j - 1]);
        }
        /*for(int k=0;k<n;k++){
        for(unsigned int j=0;j<vecchar[k].size();j++) cout<<vecchar[k][j]<<" ";
        cout<<endl;
        }
        for(int k=0;k<n;k++){
        for(unsigned int j=0;j<vecnum[k].size();j++) cout<<vecnum[k][j]<<" ";
        cout<<endl;
        }*/
        if (!all_equal) printf("Case #%d: Fegla Won\n", i + 1);
        else {
            int sum = 0;
            int len = vecnum[0].size();
            for (int h = 0; h < len; h++) {
                vector<int> temp;
                for (int j = 0; j < n; j++) temp.push_back(vecnum[j][h]);
                sort(temp.begin(), temp.end());
                if (n % 2 == 1) {
                    int median = (int)floor(n / 2);
//cout<<"median"<<median<<endl;
                    int temp_sum = 0;
                    for (int j = 0; j < n; j++) {
                        temp_sum += abs(temp[j] - temp[median]);
//cout<<temp[j]<<" ";
                    }
//cout<<endl;
//cout<<temp_sum<<" ";
                    sum += temp_sum;
                }
                else {
                    int med1 = floor((temp[n / 2 - 1] + temp[n / 2]) / 2);
                    int med2 = ceil((temp[n / 2 - 1] + temp[n / 2]) / 2);
                    int sum1 = 0;
                    int sum2 = 0;
                    for (int j = 0; j < n; j++) sum1 += abs(temp[j] - med1);
                    for (int j = 0; j < n; j++) sum2 += abs(temp[j] - med2);
                    int temp_sum = (sum1 > sum2) ? sum2 : sum1;
                    sum += temp_sum;
                }
            }
            printf("Case #%d: %d\n", i + 1, sum);
        }
    }
}
