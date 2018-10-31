#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isModified;

bool changeble(string & s) {
    bool flag = false;
    for(int i=0;i < s.size();++i) {
        switch(s[i]) {
            case '1': flag = true; s[i] = '@';break;
            case '0': flag = true; s[i] = '%';break;
            case 'l': flag = true; s[i] = 'L';break;
            case 'O': flag = true; s[i] = '0';break;
            default:break;
        }
    }
    if(flag) isModified = true;
    return flag;
}

int main() {
    int N;
    string s_team, s_password;
    isModified = false;
    vector<string> v_team, v_password;

    cin >> N;
    for(int i=0;i < N;++i) {
        cin >> s_team >> s_password;
        if(changeble(s_password)) {
            v_team.push_back(s_team);
            v_password.push_back(s_password);
        }
    }

    if(isModified) {
        cout << v_team.size() << endl;
        for(int i=0;i < v_team.size();++i){
            cout << v_team[i] << ' ' << v_password[i] << endl;
        }
    }
    else {
        if(N == 1)
            cout << "There is 1 account and no account is modified";
        else
            cout << "There are " << N <<" accounts and no account is modified";
    }

    return 0;
}