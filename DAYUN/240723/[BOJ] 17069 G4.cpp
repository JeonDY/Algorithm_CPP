#include <iostream>
#include <vector>

using namespace std;

int n;
int map[32][32];
//[y][x][degree] 0 : 가로, 1 : 대각선, 세로 
// 해당 좌표가 끝인 모든 값의 합
long long installedPipe[32][32][3];
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

long long find(){
    int ret = 0;
    //첫 좌표에 넣지 못하는 경우
    if(map[0][0] == 1 || map[0][1] == 1) return 0;
    installedPipe[0][1][0] = 1;

    for(int i = 0; i < n; ++i) {
        for(int j = 1; j < n; ++j) {
            for(int degree = 0; degree < 3; ++degree) {
                if(installedPipe[i][j][degree] == 0) continue;
                for(vector<int>::iterator it = nextPipe[degree].begin(); it != nextPipe[degree].end(); ++it) {
                    int nextI = i + nextDir[*it].first;
                    int nextJ = j + nextDir[*it].second;
                    if(nextI >= n || nextJ >= n) continue;
                    if(*it == 1) {
                        if(map[nextI - 1][nextJ] == 1) continue;
                        if(map[nextI][nextJ - 1] == 1) continue;
                    }
                    if(map[nextI][nextJ] == 1) continue;
                    installedPipe[nextI][nextJ][*it] += installedPipe[i][j][degree];
                }
            }
        }
    }
    // for(int i = 0; i < n; ++i) {
    //     for(int j = 0; j < n; ++j) {
    //         cout << installedPipe[i][j][0] + installedPipe[i][j][1] + installedPipe[i][j][2] << " ";
    //     }
    //     cout << "\n";
    // }
    return installedPipe[n - 1][n - 1][0] + installedPipe[n - 1][n - 1][1] + installedPipe[n - 1][n - 1][2]; 

}

int main(){
    init();

    cout << find();

}