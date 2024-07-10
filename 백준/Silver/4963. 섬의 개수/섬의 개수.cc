#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int grid[51][51];
bool visited[51][51];
int dx[] = {0, 0, -1, 1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, -1, 1};
int w, h;
int cnt;

void bfs(int a, int b) {
    queue<pair<int, int>> q;
    q.push(make_pair(a, b));
    visited[b][a] = true; // visited를 큐에 넣기 전에 true로 설정
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < w && ny >= 0 && ny < h) {
                if (!visited[ny][nx] && grid[ny][nx] == 1) {
                    q.push(make_pair(nx, ny));
                    visited[ny][nx] = true;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (1) {
        cin >> w >> h;
        if (w == 0 && h == 0) {
            break;
        }
        cnt = 0;
        memset(visited, false, sizeof(visited));
        queue<pair<int, int>> temp;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> grid[i][j];
                if (grid[i][j] == 1) {
                    temp.push(make_pair(j, i));
                }
            }
        }

        while (!temp.empty()) {
            int tempx = temp.front().first;
            int tempy = temp.front().second;
            temp.pop();
            if (!visited[tempy][tempx]) {
                visited[tempy][tempx] = true;
                bfs(tempx, tempy);
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
