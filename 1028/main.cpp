#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct Student {
    string id;
    string name;
    int grade;
};

bool myCompare1(const struct Student s1, const struct Student s2) {
    return s1.id < s2.id;
}

bool myCompare2(const struct Student s1, const struct Student s2) {
    if(s1.name == s2.name)
        return s1.id < s2.id;
    return s1.name < s2.name;
}

bool myCompare3(const struct Student s1, const struct Student s2) {
    if(s1.grade == s2.grade)
        return s1.id < s2.id;
    return s1.grade < s2.grade;
}


int main() {
    int N, C;
    vector<struct Student> v;
    struct Student ts;
    cin >> N >> C;
    for(int i=0;i < N;++i) {
        cin >> ts.id >> ts.name >> ts.grade;
        v.push_back(ts);
    }
    switch (C) {
        case 1: sort(v.begin(),v.end(),myCompare1);break;
        case 2: sort(v.begin(),v.end(),myCompare2);break;
        case 3: sort(v.begin(),v.end(),myCompare3);break;
        default:break;
    }
    //output
    for(int i=0;i < N;++i) {
        cout << v[i].id << ' ' << v[i].name << ' ' << v[i].grade << endl;
    }
    return 0;
}