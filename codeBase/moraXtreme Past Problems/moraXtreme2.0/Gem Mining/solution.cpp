#include <bits/stdc++.h>

#define INF (int) 1e9

using namespace std;

typedef pair<int, pair<int, int>> zone;

class cmp 
{ 
public: 
  bool operator() (const zone &a, const zone &b) const
  { 
      return (a.first > b.first); 
  }
}; 

int main() {
    int n, p, xg, yg;
    char c;
    int prices[3];
    int dxdy[8][2] = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
    cin >> n >> p;
    int grid[n][n], cost[n][n];
    cin >> xg;
    cin.ignore();
    cin >> yg;
    for (int i = 0; i < 3; i++) {
        if (cin.peek() == ',')
            cin.ignore();
        cin >> prices[i];
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cost[i][j] = INF;
            cin >> c;
            if (c == 's')
                grid[i][j] = prices[0];
            else if (c == 'r')
                grid[i][j] = prices[1];
            else if (c == 'w')
                grid[i][j] = prices[2];
            else
                grid[i][j] = 0;
        }
    cost[0][0] = 0;
    priority_queue<zone, vector<zone>, cmp> q;
    q.push({0, {0, 0}});
    
    while (!q.empty()) {
        zone currZone = q.top();
        q.pop();
        int x = currZone.second.first, y = currZone.second.second;
        for (int i = 0; i < 8; i++) {
            int x_n = x + dxdy[i][0], y_n = y + dxdy[i][1];
            if (x_n >= 0 && x_n < n && y_n >= 0 && y_n < n && cost[x_n][y_n] > cost[x][y] + grid[x_n][y_n]) {
                cost[x_n][y_n] = cost[x][y] + grid[x_n][y_n];
                q.push({cost[x_n][y_n], {x_n, y_n}});
            }
        }
    }
    
    cout << p - cost[xg][yg];
    return 0;
}
