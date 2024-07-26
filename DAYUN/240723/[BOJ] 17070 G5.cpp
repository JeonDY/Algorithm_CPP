#include <iostream>
#include <vector>

using namespace std;

int n;
int map[16][16];
//[y][x][degree] 0 : 가로, 1 : 대각선, 세로 
// 해당 좌표가 끝인 모든 값의 합
int installedPipe[16][16][3];
vector<int> nextPipe[3];
pair<int, int> nextDir[3] = {{0, 1}, {1, 1}, {1, 0}};

void init(){
    cin >> n;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> map[i][j];
        }
    }

    nextPipe[0] = {0, 1};
    nextPipe[1] = {0, 1 ,2};
    nextPipe[2] = {1, 2};
}

int find(){
    int ret = 0;
    //첫 좌표에 넣지 못하는 경우
    if(map[0][0] == 1 || map[0][1] == 1) return 0;
    installedPipe[0][1][0] = 1;
    //s : sum  s = i + j
    for(int s = 0; s < ((n - 1) * 2); ++s) {
        for(int j = 0; j <= s;  ++j) {
            int i = s - j;
            if(i >= n || j >= n) continue;
            for(int degree = 0; degree < 3; ++degree) {
                if(installedPipe[i][j][degree] == 0) continue;
                for(vector<int>::iterator it = nextPipe[degree].begin(); it != nextPipe[degree].end(); ++it) {
                    int nextI = i + nextDir[*it].first;
                    int nextJ = j + nextDir[*it].second;
                    if(nextI > n || nextJ > n) continue;
                    if(*it == 1) {
                        if(map[nextI - 1][nextJ] == 1) continue;
                        if(map[nextI][nextJ - 1] == 1) continue;
                    }
                    if(map[nextI][nextJ] == 1) continue;
                    installedPipe[nextI][nextJ][*it]++;
                }
            }
        }
    }

    return installedPipe[n - 1][n - 1][0] + installedPipe[n - 1][n - 1][1] + installedPipe[n - 1][n - 1][2]; 
    
}

int main(){
    init();

    cout << find();

}