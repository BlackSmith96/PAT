#include<iostream>
using namespace std;

int main(){
	int N, last = 0, cur, t = 0;
	cin >> N;
	for(int i=0;i < N;++i){
		cin >> cur;
		if(cur > last){
			t += (cur - last) * 6;
		}
		else if(cur < last){
			t += (last - cur) * 4;
		}
		t += 5;
		last = cur;
	}
	cout << t << endl;
	return 0;
}