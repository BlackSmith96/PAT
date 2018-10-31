#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n1, n2;
    long int t;
    vector<long int> v1, v2, v3;
    cin >> n1;
    for(int i=0;i < n1;++i) {
        cin >> t;
        v1.push_back(t);
    }
    cin >> n2;
    for(int i=0;i < n2;++i) {
        cin >> t;
        v2.push_back(t);
    }

    //merge
    int i,j;
    for(i=0,j=0;i < v1.size()&&j < v2.size();) {
        if(v1[i] < v2[j]) {
            v3.push_back(v1[i]);
            ++i;
        }
        else {
            v3.push_back(v2[j]);
            ++j;
        }
    }
    for(;i < v1.size();++i)
        v3.push_back(v1[i]);
    for(;j < v2.size();++j)
        v3.push_back(v2[j]);
    cout << v3[(n1+n2+1)/2-1];
    return 0;
}