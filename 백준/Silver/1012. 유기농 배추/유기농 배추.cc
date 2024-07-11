#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int T, M, N, K, X, Y, cnt;
bool field[50][50];
bool visited[50][50];

// 상하좌우 순서대로
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void BFS(int row, int col) {
    queue<pii> q;

    q.push({row, col});
    visited[row][col] = true;

    while(!q.empty()) {
        pii f = q.front();
        for(int i = 0; i < 4; i++) {
            int nr = f.first + dr[i];
            int nc = f.second + dc[i];
            // 배추밭의 영역에 벗어나는 경우는 생각해주면 안됨
            if(nr < 0 || nr >= M || nc < 0 || nc >= N) continue;
            // 조건 (1)과 (2)의 경우. 방문하지 않았거나, 배추가 없거나
            if(visited[nr][nc] || !field[nr][nc]) continue;
            q.push({nr, nc});
            visited[nr][nc] = true;
        }
        q.pop();
    }

    cnt++;
}

void solve() {
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            // (0, 0) 부터 (M-1, N-1)까지 다 탐색
            if(field[i][j] && !visited[i][j]) BFS(i, j);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for(int i = 0; i < T; i++) {
        cnt = 0;
        cin >> M >> N >> K;
        memset(field, 0, sizeof(field));
        memset(visited, 0, sizeof(visited));
        for(int j = 0; j < K; j++) {
            cin >> X >> Y;
            field[X][Y] = true;
        }
        solve();
        cout << cnt << endl;
    }

}