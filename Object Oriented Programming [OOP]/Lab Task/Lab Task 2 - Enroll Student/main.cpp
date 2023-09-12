#include <iostream>
using namespace std;

class Course {
    string code;
    string name;
    int maximum_students_no;
    string EnrolledStudents[1000];
    int i;

public:
    Course() {
        maximum_students_no = 0;
        i = 0;
    }
    Course(string code, string name, int maximum_students_no) {
        this->code = code;
        this->name = name;
        this->maximum_students_no = maximum_students_no;
        i = 0;
    }
    void enrollStudent() {
        string stu_name;
        cout << "Enter Name to enroll in course " << code << ": ";
        getline(cin, stu_name);
        if (i == maximum_students_no) {
            cout << "Student Full\n\n";
        } else {
            EnrolledStudents[i] = stu_name;
            ++i;
        }
    }
    void display() {
        int j = 0;
        cout << "\n\nEnrolled Students for course \"" << code << " - " << name << "\"\n";
        for (j = 0; j < i; j++) {
            cout << EnrolledStudents[j] << "\n";
        }
        cout << "\n";
    }
};

int main() {
    Course C1("CSE 1203", "DLD", 20), C2("CSE 1205", "OOP", 50);

    C1.enrollStudent();
    C1.enrollStudent();
    C1.enrollStudent();

    C2.enrollStudent();
    C2.enrollStudent();

    C1.display();
    C2.display();

    return 0;
}
