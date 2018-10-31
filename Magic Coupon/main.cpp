#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int NC, NP, t, sum=0;
    vector<int> coupon_positive, coupon_negtive, product_positive,product_negtive;

    cin >> NC;
    for(int i=0;i < NC;++i) {
        cin >> t;
        if(t > 0)
            coupon_positive.push_back(t);
        else if(t < 0)
            coupon_negtive.push_back(t);
    }
    cin >> NP;
    for(int i=0;i < NP;++i) {
        cin >> t;
        if(t > 0)
            product_positive.push_back(t);
        else if(t < 0)
            product_negtive.push_back(t);
    }

    sort(coupon_negtive.begin(),coupon_negtive.end());
    sort(coupon_positive.begin(),coupon_positive.end());
    sort(product_negtive.begin(),product_negtive.end());
    sort(product_positive.begin(),product_positive.end());

    for(int i=0,j=0;i < product_negtive.size() && j < coupon_negtive.size();++i,++j)
        sum += product_negtive[i] * coupon_negtive[j];
    for(int i=product_positive.size()-1,j=coupon_positive.size()-1;i>=0 && j >=0;--i,--j)
        sum += product_positive[i] * coupon_positive[j];
    cout << sum << endl;
    return 0;
}