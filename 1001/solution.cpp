#include<iostream>
#include<vector>
using namespace std;

int main(){
	long a, b, ans;
	bool flag = true;
	cin >> a >> b;
	ans = a + b;
	if(ans < 0){
		flag = false;
		ans = -ans;
	}
	else if(ans == 0){
		cout << 0 << endl;
		return 0;
	}
	vector<int> v;
	for(;ans;ans /= 10){
		v.push_back(ans % 10);
	}
	if(!flag)
		cout << '-';
	for(int i=v.size()-1;i >= 0;--i){
		if(i % 3 == 2 && i != 0 && i != v.size()-1)
			cout << ',';
		cout << v[i];
	}
	cout << endl;
	return 0;
}