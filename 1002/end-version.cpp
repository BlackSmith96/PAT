/*
 * 参考了https://www.liuchuo.net/archives/1890
 * 基于多项式的指数有最大值，可以将其存在一个数组中
 *
 */

#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int k1,k2;
float poly[1001] = {0};
int exp;
float cof;
int c = 0;

int main(){
	cin >> k1;
	for(int i = 0;i < k1;++i){
		cin >> exp >> cof;
		poly[exp] = cof;
	}
	cin >> k2;
	for(int i = 0;i < k2;++i){
		cin >> exp >> cof;
		poly[exp] += cof;
	}
	for(int i = 0;i < 1001;++i){
		if(poly[i] != 0)
			c++;
	}
	cout << c;
	for(int i = 1000;i >= 0;--i){
		if(poly[i] != 0)
			printf(" %d %.1f",i,poly[i]);
	}
	return 0;
}