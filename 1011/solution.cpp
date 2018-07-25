#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	char c[4] = "WTL";
	float profit = 1;
	float t;
	for(int i = 0;i < 3;++i){
		int max_i = -1;
		float max_rate = 0;
		for(int j = 0;j < 3;++j){
			cin >> t;
			if(t > max_rate){
				max_i = j;
				max_rate = t;
			}
		}
		cout << c[max_i] << ' ';
		profit *= max_rate;
	}
	printf("%.2f\n",(profit * 0.65 - 1)*2);
	return 0;
}