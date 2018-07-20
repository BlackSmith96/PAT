#include<iostream>
#include<string>
using namespace std;

int main(){
	int M;
	int unlocked_time = 24 * 3600, locked_time = -1;
	string unlock_user,lock_user;
	cin >> M;
	for(int i=0;i < M;++i){
		string t;
		cin >> t;
		int h1, m1, s1, h2, m2, s2;
        scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);
        int timeIn = h1 * 3600 + m1 * 60 + s1;
        int timeOut = h2 * 3600 + m2 * 60 + s2;
        if(timeIn < unlocked_time){
        	unlocked_time = timeIn;
        	unlock_user = t;
        }
        if(timeOut > locked_time){
        	locked_time = timeOut;
        	lock_user = t;
        }
	}
	cout << unlock_user << ' ' << lock_user << endl;
	return 0;
}