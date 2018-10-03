#include <iostream>
#include <string>
using namespace std;

const char chs[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C'};

string int2radix13(int t) {
    string s;
    while(t) {
        s = chs[t % 13] + s;
        t /= 13;
    }
    if(s.size() == 0)
        s = "00";
    else if(s.size() == 1)
        s = '0' + s;
    return s;
}
int main() {
    int a[3];
    for(int i=0;i < 3;++i) {
        cin >> a[i];
    }
    cout << '#';
    for(int i=0;i < 3;++i) {
        cout << int2radix13(a[i]);
    }
    cout << endl;
    return 0;
}