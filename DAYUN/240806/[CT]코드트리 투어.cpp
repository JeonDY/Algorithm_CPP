/*
    Code Tree : 코드트리 투어
	
    삼성 SW 역량테스트 2024 상반기 오전 2번 문제
    https://www.codetree.ai/training-field/frequent-problems/problems/codetree-tour/description?page=1&pageSize=5
*/


#include <queue>
#include <cstring>
#include <iostream>

using namespace std;

#define MAX_W 2000010

int n;
int m;
int dist[2010];
int graph[2010][2010];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> path;

void init(int n, int m)
{
    fill(&graph[0][0], &graph[2010][0], MAX_W);
    int v1, v2, w;
    for(int i = 0; i < m; ++i) {
        cin >> v1 >> v2 >> w;
        graph[v1][v2] = w < graph[v1][v2] ? w : graph[v1][v2];
    }
}

void make_trip(int id, int revenud, int dest)
{}

void change_start(int s)
{
    fill(&dist[0], &dist[n], MAX_W);
    while(!path.empty()) path.pop();

    path.push({0, 0});

    while(!path.empty()) {
        
    }

}

void cancel_trip(int id)
{}

int best_trip()
{return 0;}

int main() {

    int s;
    int id;
    int cmd;
    int dest;
    int query;
    int revenue;

    for(int q = 0; q < query; ++q) {
        cin >> cmd;
        switch(cmd) {
            case 100 : 
                cin >> n >> m;
                init(n,m);
                change_start(0);
                break;
            case 200:
                cin >> id >> revenue >> dest;
                make_trip(id, revenue, dest);
                break;
            case 300 :
                cin >> id;
                cancel_trip(id);
                break;
            case 400:
                cout << best_trip() <<"\n";
                break;
            case 500:
                cin >> s;
                change_start(s);
                break;
        }
    }
    return 0;
}