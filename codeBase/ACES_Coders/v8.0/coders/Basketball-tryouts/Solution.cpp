#include <iostream>
#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


bool DEBUG= false;

vector<pair<int, int> > normalize(vector<pair<int, int> > v) {
    vector<pair<int, int> > ret;
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        while (ret.size() && ret.back().first <= v[i].first &&
               ret.back().second <= v[i].second) {
            ret.pop_back();
        }
        ret.push_back(v[i]);
    }
    return ret;
}

vector<pair<int, int> > rev(vector<pair<int, int> > v) {
    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) v[i].first = -v[i].first;
    for (int i = 0; i < v.size(); i++) v[i].second = -v[i].second;
    return v;
}

long long solve(const vector<pair<int, int> >& a, int ai1, int ai2,
               const vector<pair<int, int> >& b, int bi1, int bi2,
               bool swapped) {
    if (ai2-ai1 <= 50 || bi2-bi1 <= 50) {
        long long ret = 0;
        for (int i = ai1; i < ai2; i++)
            for (int j = bi1; j < bi2; j++) {
                if (swapped) {
                    ret = max(ret, (long long)min(0, b[j].first-a[i].first) *
                                   (b[j].second-a[i].second));
                } else {
                    ret = max(ret, (long long)max(0, b[j].first-a[i].first) *
                                   (b[j].second-a[i].second));
                }
            }
        return ret;
    }

    vector<pair<int, int> > b1, b2;
    int i = (ai2+ai1)/2;
    for (int j = bi1; j+1 < bi2; j += 2) {
        long long v1 = (long long)(b[j].first-a[i].first) *
                       (b[j].second-a[i].second);
        long long v2 = (long long)(b[j+1].first-a[i].first) *
                       (b[j+1].second-a[i].second);
        if (v1 < v2) {
            b1.push_back(b[j]); b1.push_back(b[j+1]); b2.push_back(b[j+1]);
        } else {
            b1.push_back(b[j]); b2.push_back(b[j]); b2.push_back(b[j+1]);
        }
    }
    if ((bi2-bi1)%2) { b1.push_back(b[bi2-1]); b2.push_back(b[bi2-1]); }

    return max(solve(b1, 0, b1.size(), a, ai1, i, !swapped),
               solve(b2, 0, b2.size(), a, i, ai2, !swapped));
}

int main() {
    int N, D;
    scanf("%d %d",&N,&D);

//    vector<pair<int, int> > A, C;

    int ar_st[N];
    int ar_en[N];
    char ar_type[N];
    int ar_score[N];

    int countA=0,countB=0,countC=0;

    long ansA,ansB=0,ansC=0;

    int n=0;
    for(n=0;n<N;n++){
        int st,en,sc;
        char type;
        scanf("%d %d %c %d",&ar_st[n],&ar_en[n],&ar_type[n],&ar_score[n]);

        if(ar_type[n]=='A')countA++;
        if(ar_type[n]=='B')countB++;
        if(ar_type[n]=='C')countC++;

    }

    if(DEBUG) {
        for (n = 0; n < N; n++) {
            printf("DEBUG: %d %d %c %d\n", ar_st[n], ar_en[n], ar_type[n], ar_score[n]);

        }
    }


    vector<pair<int, int> > A(countA), C(countC);
    countA=0,countB=0,countC=0;
    for(n=0;n<N;n++){//buyers
        if(ar_type[n]=='A'){
            A[countA].first=ar_en[n]+1;
            A[countA].second=ar_score[n];
            ansA+=(ar_en[n]-ar_st[n]+1)*ar_score[n];

            countA++;


        } else if (ar_type[n]=='B'){
            ansB+=(ar_en[n]-ar_st[n]+1)*ar_score[n];
            countB++;
        }else{//producers
            C[countC].first=ar_st[n];
            C[countC].second=ar_score[n];
            ansC+=(ar_en[n]-ar_st[n]+1)*ar_score[n];
            countC++;
        }
    }
    if(DEBUG) {
        printf("DEBUG: added.A %d addec.B %d added.C %d\n", countA, countB, countC);
    }

//    A = rev(normalize(rev(A)));
//    C = normalize(C);

    C=rev(normalize(rev(C)));
    A=normalize(A);

//    int ansAC=solve(A, 0, A.size(), C, 0, C.size(), false);

    long ansAC=solve(C, 0, C.size(),A, 0, A.size(),  false);
    if(DEBUG) {
        printf("A:%ld B:%ld C:%ld\n", ansA, ansB, ansC);
        printf("A+C:%ld\n", ansA + ansC);
        printf("ACnew:%ld\n", ansAC);
        printf("0LD:%ld NEW:%ld\n", ansA + ansB + ansC, ansA + ansB + ansC + ansAC);
    }


    printf("%ld %ld\n",ansA + ansB + ansC, ansA + ansB + ansC + ansAC);

}
