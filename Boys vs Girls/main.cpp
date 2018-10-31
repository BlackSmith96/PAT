#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct {
    string name;
    int grade;
    string no;
} Student;

int main() {
    vector<Student> girls, boys;
    int N, grade, girl_id = -1, boys_id = -1;
    string name, no;
    char gender;

    cin >> N;
    for(int i=0;i < N;++i) {
        cin >> name >> gender >> no >> grade;
        if(gender == 'M') {
            if(boys_id == -1 || grade < boys[boys_id].grade)
                boys_id = boys.size();

            Student s;
            s.name = name;
            s.grade = grade;
            s.no = no;
            boys.push_back(s);
        }
        else {
            if(girl_id == -1 || grade > girls[girl_id].grade)
                girl_id = girls.size();

            Student s;
            s.name = name;
            s.grade = grade;
            s.no = no;
            girls.push_back(s);
        }
    }

    if(girl_id == -1)
        cout << "Absent" << endl;
    else
        cout << girls[girl_id].name << ' ' << girls[girl_id].no << endl;

    if(boys_id == -1)
        cout << "Absent" << endl;
    else
        cout << boys[boys_id].name << ' ' << boys[boys_id].no << endl;

    if(girl_id == -1 || boys_id == -1)
        cout << "NA" << endl;
    else
        cout << girls[girl_id].grade - boys[boys_id].grade << endl;

    return 0;
}