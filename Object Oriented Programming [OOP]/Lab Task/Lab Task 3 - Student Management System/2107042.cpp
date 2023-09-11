#include <iostream>
using namespace std;

class StudentRecordManager;

class Student{
    int ID;
    string NAME;
    int AGE;
    float SCORE;
public:
    friend class StudentRecordManager;
    Student()
    {
        SCORE = 0;
    }
    Student(int id, string name, int age, float score)
    {
        ID = id;
        NAME = name;
        AGE = age;
        SCORE = score;
    }
    ~ Student()
    {
        //cout << "Student Left" << endl;
    }
    void display()
    {
        cout << "ID : " << ID << endl;
        cout << "Name : " << NAME << endl;
        cout << "Age : " << AGE << endl;
        cout << "Score : " << SCORE << endl;
    }
    friend void searchStudent(StudentRecordManager admin, int id);
};

class StudentRecordManager{
    Student stu[100];
    int total_stud;
public:
    friend class Student;
    StudentRecordManager()
    {
        total_stud = 0;
    }
    void AddNewStudent(int id, string name, int age, float score)
    {
        stu[total_stud].ID = id;
        stu[total_stud].NAME = name;
        stu[total_stud].AGE = age;
        stu[total_stud].SCORE = score;
        total_stud++;
    }
    void DisplayAll()
    {
        cout << "Showing all student details : \n\n";
        for(int i = 0; i < total_stud; i++){
            stu[i].display();
            cout << "\n";
        }
    }
    float AverageScore()
    {
        float sum = 0;
        for(int i = 0; i < total_stud; i++){
            sum += stu[i].SCORE;
        }
        float avg =  sum / total_stud;
        cout << "Average Score of " << total_stud << " Students : " << avg << "\n\n";
    }
    friend void searchStudent(StudentRecordManager admin, int id);
};

void searchStudent(StudentRecordManager admin, int id)
{
    for(int i = 0; i < admin.total_stud; i++){
        if(id == admin.stu[i].ID){
            cout << "Search Result : \n";
            admin.stu[i].display();
            cout << "\n";
            return;
        }
    }
    cout << "ID with " << id << " Student not found\n" << endl;
}

int main()
{
    StudentRecordManager admin;
    admin.AddNewStudent(100, "Abdul", 20, 88.75); //Adding new students
    admin.AddNewStudent(101, "Babul", 20, 87.50);
    admin.AddNewStudent(102, "Dola", 19, 90.25);
    admin.AddNewStudent(103, "Emon", 21, 91.70);

    admin.DisplayAll(); //Displaying All Student details
    admin.AverageScore(); //Displaying Average Score of All

    searchStudent(admin, 102); //Searching a student with ID
    searchStudent(admin, 105);

    admin.AddNewStudent(104, "Fahim", 20, 92.70);
    admin.AddNewStudent(105, "Hamim", 22, 80.40);

    admin.DisplayAll();
    admin.AverageScore();

    searchStudent(admin, 103);
    searchStudent(admin, 105);

    return 0;
}
