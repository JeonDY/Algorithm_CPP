#include <iostream>
#include <queue>

using namespace std;

int A, B;
bool dvList[100010];

//소수찾기 
void findDv(){
    dvList[1] = true;
    dvList[0] = true;
    for(int i = 2; i <= B; ++i) {
        if(dvList[i]) continue;
        int j = i << 1;
        while(j <= B) {
            dvList[j] = true;
            j += i;
        }
    }
}


//소인수분해 길이
bool find(int num) {
    int i = 1;
    int ret = 0;
    while(num != 1){
        i++; 
        if(dvList[i]) continue;
        while(num % i == 0) {
            num /= i;
            ret++;
        }
    }

    if(dvList[ret]) return false;
    return true;
}

int main(){
    int result = 0;

    cin >> A >> B;

    findDv();

    for(int i = A; i <= B; ++i){
        if(find(i)) {
            result++;
        }
    }
    cout << result;
}