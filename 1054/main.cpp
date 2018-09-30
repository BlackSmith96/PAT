#include <iostream>
#include <map>
using namespace std;

int main() {
    int N,M,temp;
    map<int, int> mp;
    cin >> M >> N;
    for(int i=0;i < N;++i)
        for(int j=0;j < M;++j) {
            cin >> temp;
            if(mp.find(temp) == mp.end()) mp[temp] = 0;
            mp[temp]++;
        }

    int key=0, max=0;
    for(map<int,int>::iterator it = mp.begin();it != mp.end();++it) {
        if(it->second > max) {
            key = it->first;
            max = it->second;
        }
    }
    cout << key;
    return 0;
}