#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Student{
public:
    string name;
    string id;
    int grade;
    Student(string t_name, string t_id, int t_grade):name(t_name),id(t_id),grade(t_grade){};
};

bool myCompare(const Student stu1, const Student stu2) { return stu1.grade > stu2.grade; }

vector<Student> students;

int main() {
    int N,bound_bottom,bound_up;
    cin >> N;
    string t_name,t_id;
    int t_grade;
    for(int i=0;i < N;++i){
        cin >> t_name >> t_id >> t_grade;
        students.push_back(Student(t_name,t_id,t_grade));
    }
    cin >> bound_bottom >> bound_up;

    sort(students.begin(),students.end(),myCompare);

    int count = 0;
    for(size_t i = 0; i != students.size(); ++i){
        if(students[i].grade >= bound_bottom && students[i].grade <= bound_up) {
            cout << students[i].name << ' ' << students[i].id << endl;
            ++count;
        }
    }
    if(count == 0)
        cout << "NONE" << endl;
    return 0;
}