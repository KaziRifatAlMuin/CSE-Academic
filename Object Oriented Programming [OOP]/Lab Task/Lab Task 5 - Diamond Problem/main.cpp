#include <iostream>
using namespace std;

class student
{
protected:
    int roll_no;
public:
    void setRoll(int r)
    {
        roll_no = r;
    }
    void displayRoll()
    {
        cout << "Roll No : " << roll_no << endl;
    }
};

class test : virtual public student
{
protected:
    int sub1, sub2;
public:
    void setMark(int s1, int s2)
    {
        sub1 = s1;
        sub2 = s2;
    }
    void showMark()
    {
        cout << "Marks of sub1 : " << sub1 << endl;
        cout << "Marks of sub2 : " << sub2 << endl;
    }
};

class sports : virtual public student
{
protected:
    int score;
public:
    void setScore(int s)
    {
        score = s;
    }
    void showScore()
    {
        cout << "Sports Score : " << score << endl;
    }
};

class result : public test, public sports
{
    int total;
public:
    void display()
    {
        total = sub1 + sub2 + score;
        cout << "Total Score : " << total << endl;
    }
};

int main()
{
    result s1;
    s1.setRoll(2107042);
    s1.setMark(90, 95);
    s1.setScore(10);

    s1.displayRoll();
    s1.showMark();
    s1.showScore();
    s1.display();


    return 0;
}
