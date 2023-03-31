// https://www.acmicpc.net/problem/1012
#include <bits/stdc++.h>
using namespace std;

int TRY;
int M, N, K;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int adj[55][55];
int visited[55][55];
vector<int> ret;
void dfs(int x, int y) {
  // cout << "visited: " << x << ", " << y << "\n";
  // 방문하고 visited = 1;
  visited[x][y] = 1;
  
  // 
  for (int i=0; i<4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    // cout << nx << ", " << ny << "\n";
    if (nx < 0 || ny < 0 || M-1 < nx || N-1 < ny || adj[nx][ny] == 0) continue;
    if (visited[nx][ny] == 1) continue;

    dfs(nx, ny);
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> TRY;
  while (0 < TRY) {
    TRY--;
    
    cin >> M >> N >> K;
    for (int i=0; i<M; i++) {
      for (int j=0; j<N; j++) {
        adj[i][j] = 0;
      }
    }
    for (int k=0; k<K; k++) {
      int x, y;
      cin >> x >> y;
      adj[x][y] = 1;
    }
    
    for (int q=0; q<55; q++) {
      for (int w=0; w<55; w++) {
        visited[q][w] = 0;
      }  
    }

    int v = 0;
    for (int i=0; i<M; i++) {
      for (int j=0; j<N; j++) {
        if (!adj[i][j] || visited[i][j]) continue;
        dfs(i, j);
        v++;
      }
    }
    ret.push_back(v);
  }

  for (int v: ret) {
    cout << v << "\n";
  }
  
  return 0;
}