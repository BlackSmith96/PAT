#include<iostream>
#include<string>
using namespace std;

int main(){
	long a, b;
	cin >> a >> b;
	string ans = to_string(a+b);
	for(auto i = 0;i != ans.size();++i){
		cout << ans[i];
		if(ans[i] == '-') continue;
		if((i + 1) % 3 == ans.size() % 3 && i != ans.size()-1) cout << ',';
	}
	cout << endl;
	return 0;
}