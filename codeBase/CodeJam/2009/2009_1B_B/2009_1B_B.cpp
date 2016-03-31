// C++ program to find the smallest number which greater than a given number
// and has same set of digits as given number
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
 
// Utility function to swap two digits
void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
 
// Given a number as a char array number[], this function finds the
// next greater number.  It modifies the same array to store the result
string findNext(char number[], int n)
{
    int i, j;
 
    // I) Start from the right most digit and find the first digit that is
    // smaller than the digit next to it.
    for (i = n-1; i > 0; i--)
        if (number[i] > number[i-1])
           break;
 
    // If no such digit is found, then all digits are in descending order
    // means there cannot be a greater number with same set of digits
    if (i==0)
    { 
        string str(number);
        return str;
    }
 
    // II) Find the smallest digit on right side of (i-1)'th digit that is
    // greater than number[i-1]
    int x = number[i-1], smallest = i;
    for (j = i+1; j < n; j++)
        if (number[j] > x && number[j] < number[smallest])
            smallest = j;
 
    // III) Swap the above found smallest digit with number[i-1]
    swap(&number[smallest], &number[i-1]);
 
    // IV) Sort the digits after (i-1) in ascending order
    sort(number + i, number + n);
 
    string str1(number);
    return str1;
}
 
// Driver program to test above function
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