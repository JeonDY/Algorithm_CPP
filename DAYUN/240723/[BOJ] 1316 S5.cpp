#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int N;
bool alpha[30];
bool groupWord(){
    string str;
    memset(alpha, false, sizeof(alpha));

    cin >> str;
    for(int i = 0; i < str.size(); ++i) {
        if(alpha[str[i] - 'a']) { 
            return false;
        }
        if(i == str.size()) break;
        alpha[str[i]-'a'] = true;
        int j = i;
        while(str[i] == str[j]) {
            i++;
        }
        i--;
    }
    return true;
}

int main(){
    int ret = 0;

    cin >> N;
    string str;
    for(int i = 0; i < N; ++i) {
        if(groupWord()) ret++;
    }
    cout << ret;
}