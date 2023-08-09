#include <iostream>
using namespace std;

class RecordManager;

class Student{
    int studentID;
    string studentName;
    float gpa;
public:
    friend class RecordManager;
    Student()
    {
        gpa = 0.0;
    }
    Student(int studentID, string studentName, float gpa)
    {
        this->studentID = studentID;
        this->studentName = studentName;
        this->gpa = gpa;
    }
    friend istream & operator >> (istream &in, Student &S)
    {
        cout << "Enter Student ID : ";
        in >> S.studentID;
        fflush(stdin);
        cout << "Enter Student Name : ";
        in >> S.studentName;
        fflush(stdin);
        cout << "Enter Student GPA : ";
        in >> S.gpa;
        fflush(stdin);
        return in;
    }
    friend ostream & operator << (ostream &out, Student &S)
    {
        out << "ID : " << S.studentID << endl;
        out << "Name : " << S.studentName << endl;
        out << "GPA : " << S.gpa << endl;
        return out;
    }
    operator++(int)
    {
        gpa = gpa + 0.1;
    }
};

class RecordManager{
public:
    friend class Student;
    static float CalculateAverageGPA(Student * students, int numStudents)
    {
        float sum = 0;
        for(int i = 0; i < numStudents; i++){
            sum = sum + students->gpa;
            students++;
        }
        return sum / numStudents;
    }
    static void CopyStudents(Student * source, Student * destination, int numStudents)
    {
        for(int i = 0; i < numStudents; i++){
            destination[i] = source[i];
        }
    }
};

int main()
{
    RecordManager admin;
    int n;
    cout << "Number of Students : ";
    cin >> n;
    Student s1[n], s2[n];
    for(int i = 0; i < n; i++){
        cin >> s1[i];
    }
    admin.CopyStudents(s1, s2, n);

    cout << "\nStudent Details : \n";
    for(int i = 0; i < n; i++){
        cout << s2[i];
    }
    cout << "\nAverage GPA : " << admin.CalculateAverageGPA(s2, n) << "\n\n\n";
    for(int i = 0; i < n; i++){
        s2[i]++;
    }
    cout << "\nStudent Details : \n";
    for(int i = 0; i < n; i++){
        cout << s2[i];
    }
    cout << "\nAverage GPA : " << admin.CalculateAverageGPA(s2, n) << "\n\n\n";

    return 0;
}
