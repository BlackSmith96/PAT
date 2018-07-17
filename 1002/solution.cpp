#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int k1, k2;
typedef struct {
	int exp;
	float coeff;
} Term;

vector<Term> poly1, poly2, ans;

int main(){
	cin >> k1;
	for(int i = 0;i < k1;++i){
		Term t;
		cin >> t.exp >> t.coeff;
		poly1.push_back(t);
	}
	cin >> k2;
	for(int i = 0;i < k2;++i){
		Term t;
		cin >> t.exp >> t.coeff;
		poly2.push_back(t);
	}

	int i, j;
	for(i=0,j=0;i != k1 && j != k2;){
		if(poly1[i].exp > poly2[j].exp){
			ans.push_back(poly1[i]);
			++i;
		}
		else if(poly1[i].exp < poly2[j].exp){
			ans.push_back(poly2[j]);
			++j;
		}
		else{
			Term t;
			t.exp = poly1[i].exp;
			t.coeff = poly1[i].coeff + poly2[j].coeff;
			if(t.coeff != 0)
				ans.push_back(t);
			++i;
			++j;
		}
	}

	for(;i != k1;++i)
		ans.push_back(poly1[i]);
	for(;j != k2;++j)
		ans.push_back(poly2[j]);


	//output
	cout << ans.size();
	for(auto i=0;i != ans.size();++i){
		printf(" %d %.1f",ans[i].exp,ans[i].coeff);
	}
	cout << endl;
	return 0;
}