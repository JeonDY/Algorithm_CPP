#include <iostream>
#include <cstring>

using namespace std;

int n;
int m;
int g;
int r;
int map[50][50];
int yellow[10][2];
int red[5];
int green[5];
int spreadMap[50][50];
int cntYellow;

void init();
void initRG();
int chooseG();

int main(){
    init();

    //choose 
    int i = 0;
    initRG();
    //Choose Red and Green

    

}

void initRG(){
    //memset(green, 0, sizeof(green));
    // memset(red, 0, sizeof(red));

    int cnt = 0;
    for(int i = 0; i < g; ++i){
        green[i] = i;
    }
    for(int i = 0; i < r; ++i) {
        red[i] = i + g;
    }
    return;
}

bool chooseRG(){
    //choose red
    while()
}

void init(){
    cntYellow = 0;

    cin >> n >> m >> g >> r;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> map[i][j];
            if(map[i][j] == 2) {
                yellow[cntYellow++][0] = i;
                yellow[cntYellow++][0] = j;
            }
        }
    }


}