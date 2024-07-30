#include <iostream>

using namespace std;

int R, C, K;
int ret;
char map[5][5];
bool visited[5][5];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int cnt = 0;

void dfs(int r, int c, int k){
    if(r == 0 && c == C - 1 && k == K) {
        ret++;
        return;
    }

    if(k >= K) return;
    if(cnt > 100) return;

    for(int i = 0; i < 4; ++i) {
        int nextR = r + dir[i][0];
        int nextC = c + dir[i][1];

        if(nextR < 0 || nextR >= R || nextC < 0 || nextC >= C) continue;
        if(visited[nextR][nextC]) continue;
        visited[nextR][nextC] = true;
        dfs(nextR, nextC, k + 1);
        visited[nextR][nextC] = false;
    }
    return;
}

int main(){
    cin >> R >> C >> K;
    char ch;
    for(int i = 0; i < R; ++i) {
        for(int j = 0; j < C; ++j) {
            cin >> ch;
            if(ch == 'T') visited[i][j] = true;
        }
    }

    visited[R - 1][0] = true;
    dfs(R - 1, 0, 1);
    cout << ret;
}