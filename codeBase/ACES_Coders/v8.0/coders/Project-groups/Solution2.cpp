/*
  This is a solution posted by the hackerrank user : https://www.hackerrank.com/Mevan_Niluminda after the competition.
  The solution achieved 100% marks.
  
  Time complexity: O(N^2)
  Space complexity: O(D^2)


*/
#include <bits/stdc++.h> 
using namespace std; 
struct point_t
{
    int x;
    int y;
};

unsigned int squared_distance(const point_t &p1, const point_t &p2)
{
    int a = p2.x - p1.x;
    int b = p2.y - p1.y;
    return a*a + b*b;
}
void vec_print(int num[],int N){
    for(int i=0;i<N;i++){
        cout<<num[i]<<" ";
    }
    cout<<endl;
}


int main() 
{  
    int N,D;
    cin>>N>>D;
    map<string, pair<double,double> > d;
    vector<string> names;
    for(int i=0;i<N;i++){
        string ty;
        double number;
        cin>>ty>>number;
        names.push_back(ty);
        d[ty].first = number;
    }
    for(int i=0;i<N;i++){
        string ty;
        double number;
        cin>>ty>>number;
        d[ty].second = number;
    }
    
    vector<point_t > points;
    for ( int j=0;j<N;j++) {
        double p = d[names[j]].first;
        double q = d[names[j]].second;
        double a = ((double) D)/(tan(p)+tan(-q));
        double b = a*(tan(p));
        a=a-0.5;
        b=b-0.5;
        point_t ii;
        ii.x = round(b);
        ii.y = round(a);
        points.push_back(ii);
        //cout<<ii.x<<" "<<ii.y<<endl;
    }
    int nb_triangles = 0;
    
      
    int distances[(D*D)+(D*D)+1];
    //cout<<D<<" D"<<endl;
    int dis[N];
    memset(distances,0,sizeof distances);
    for (int p=0;p<N;p++)
    {
       // cout<<p<<endl;
       // memset(distances,0,N);
        for (int q=0;q<N;q++)
        {
           
            int dist = squared_distance(points[p], points[q]);
            distances[dist]++;
            dis[q] = dist;
          
        }
        
       
      //  vec_print(distances,N);
        int s =1;
        for(int i=0;i<N;i++){
            
            if(distances[dis[i]]>0){
                nb_triangles = nb_triangles + ((distances[dis[i]]*(distances[dis[i]]-1))>>1);
                distances[dis[i]] = 0;
            }
           
          //  cout<<distances[i]<<" "<<s<<" ";
        }
      
       // cout<<endl;
       // cout<<nb_triangles<<" sdjcisjdc"<<endl;
    }

    
    cout<<nb_triangles;
    return 0; 
} 
