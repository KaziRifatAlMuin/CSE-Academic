#include <iostream>
using namespace std;

class staffMember{
protected:
    string name;
    int ID;
    double base_salary;
public:
    staffMember(string name, int ID, double base_salary)
    {
        this->name = name;
        this->ID = ID;
        this->base_salary = base_salary;
    }
    virtual double calculateSalary() = 0;
    virtual void displayDetails() = 0;
};

class Professor : virtual public staffMember{
private:
    int publications;
    int researchgrants;
public:
    Professor(string name, int ID, double base_salary, int publications, int researchgrants) : staffMember(name, ID, base_salary)
    {
        this->publications = publications;
        this->researchgrants = researchgrants;
    }
    double calculateSalary()
    {
        double salary;
        salary = base_salary + publications * 1000 + researchgrants * 500;
        return salary;
    }
    void displayDetails()
    {
        cout << "Details of Professor : \n";
        cout << "Name : " << name << "\n";
        cout << "ID : " << ID << "\n";
        cout << "Base Salary : " << base_salary << "\n";
        cout << "Publications : " << publications << "\n";
        cout << "Researchgrants : " << researchgrants << "\n\n";
    }
};

class AdminStaff : virtual public staffMember{
private:
    string designation;
    int overtimeHours;
public:
    AdminStaff(string name, int ID, double base_salary, string designation, int overtimeHours) : staffMember(name, ID, base_salary)
    {
        this->designation = designation;
        this->overtimeHours = overtimeHours;
    }
    double calculateSalary()
    {
        double salary;
        salary = base_salary + overtimeHours * 500;
        return salary;
    }
    void displayDetails()
    {
        cout << "Details of AdminStaff : \n";
        cout << "Name : " << name << "\n";
        cout << "ID : " << ID << "\n";
        cout << "Base Salary : " << base_salary << "\n";
        cout << "Designation : " << designation << "\n";
        cout << "Overtime Hours : " << overtimeHours << "\n\n";
    }
};

int main()
{
    staffMember *s1, *s2;
    s1 = new Professor("Mr. ABC", 101, 60000, 5, 10);
    s2 = new AdminStaff("Mr. DEF", 102, 40000, "Lecturer", 20);

    s1->displayDetails();
    double salary1 = s1->calculateSalary();
    cout << "Calculated Salary: " << salary1 << "\n\n";

    s2->displayDetails();
    double salary2 = s2->calculateSalary();
    cout << "Calculated Salary: " << salary2 << "\n\n";

    delete s1;
    delete s2;

    return 0;
}
