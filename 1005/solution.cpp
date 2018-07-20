#include<iostream>
#include<string>
#include<vector>
using namespace std;

string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main(){
	string N;
	int sum=0;
	cin >> N;
	for(int i=0;i < N.size();++i){
		sum += (N[i] - '0');
	}
	string sum_string = to_string(sum);
	cout << arr[sum_string[0]-'0'];
	for(int i=1;i < sum_string.size();++i){
		cout << ' ' << arr[sum_string[i]-'0'];
	}
	cout << endl;
}