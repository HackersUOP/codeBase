/*
Copyright Hackers' Club, University Of Peradeniya
Author : E/13/181
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
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
 
void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
 
string findNext(char number[], int n)
{
    int i, j;
 
    for (i = n-1; i > 0; i--)
        if (number[i] > number[i-1])
           break;
    if (i==0)
    { 
        string str(number);
        return str;
    }
 
    int x = number[i-1], smallest = i;
    for (j = i+1; j < n; j++)
        if (number[j] > x && number[j] < number[smallest])
            smallest = j;
 

    swap(&number[smallest], &number[i-1]);
 
    sort(number + i, number + n);
 
    string str1(number);
    return str1;
}

int main()
{
 
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string number;
        cin>>number;
        char digits[21];
        strcpy(digits, number.c_str());
        int n = strlen(digits);
        string ans=findNext(digits, n);
        if(ans==number){
            vector<int> ints; 
            for(int j=0;j<n;j++){
                int u=number[j]-'0';
                ints.push_back(u);
            }
            sort(ints.begin(),ints.end());
            int ind=0;
            //cout<<ind;
            while(ints[ind]==0){
                ind++;
            }
            //cout<<ind;
            int y=ints[ind];
            ints.erase(ints.begin()+ind);
            ints.insert(ints.begin(),y);
            ints.insert(ints.begin()+1,0);   
            printf("Case #%d: ",i+1);
            for(int j=0;j<n+1;j++) printf("%d",ints[j]);
            printf("\n");
            //cout<<"Ha";
        } 
        else printf("Case #%d: %s\n",i+1,ans.c_str());
    }
    return 0;
}
