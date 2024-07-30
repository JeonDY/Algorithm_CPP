//[BOJ] 18870 S2

/*
    시뮬레이션? 모든 위치에서 가능한 빨간액, 초록액
    위치를 잡는다.
    모든 액체는 한칸씩(상하좌우로) 기존의 색은 사라진다.
    각 빨간 배양액과 초록 배양액이 만날 수 있는지 찾는다.
    두 위치에서 배양액이 만날 수 있는지 확인한다.
    dfs로 최대 두위치에서 배양액이 가능한지 찾아본다.
    만약 둘이 만나는 길이 없다면? 안만나는 길이 있는지 확인한다.

    1. 조합을 통해 빨간색 배양액, 초록색 배양액을 조사한다.
    2. 시간 순서대로 맵을 만든다. 만나면 꽃을 피우고 그 위치는 -1로 다시는 배양액이 퍼지지 않도록 한다.
    3.최대 가능성을 구한다. 

*/


#include <iostream>
#include <vector>

using namespace std;

int n, m, g, r;
int map[50][50];
vector<vector<int>> coombinationSpot;
int spots[10][2];
int cntSpot = 0;

void init();

int main(){
    init();
    
    //choose most flower when combination vect
    vector<int> green(g);
    vector<int> red(r);
    int maxGreenIndex = 0;
    while(maxGreenIndex < g) {
        
    }

    
}


void init(){
    cin >> n >> m >> g >> r;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> map[i][j];
            if(map[i][j] == 2) {
                spots[cntSpot++][0] = i;
                spots[cntSpot++][1] = j;
            }
        }
    }
}