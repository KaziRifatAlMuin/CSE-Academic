#include <iostream>
#include<fstream>
using namespace std;

class Animal{
    string name;
    string habitat;
public:
    Animal(string name, string habitat)
    {
        this->name = name;
        this->habitat = habitat;
    }
    virtual void displayDetails() = 0;
    string get1()
    {
        return name;
    }
    string get2()
    {
        return habitat;
    }
};

class Mammal : virtual public Animal{
    string diettype;
    int numlegs;
public:
    string get3()
    {
        return diettype;
    }
    int get4()
    {
        return numlegs;
    }
    Mammal(string name, string habitat, string diettype, int numlegs) : Animal(name, habitat)
    {
        this->diettype = diettype;
        this->numlegs = numlegs;
    }
    void displayDetails()
    {
        //
    }
};

class Bird : virtual public Animal{
    double wingspan;
    bool canfly;
public:
    double get5()
    {
        return wingspan;
    }
    bool get6()
    {
        return canfly;
    }
    Bird(string name, string habitat, double wingspan, bool canfly) : Animal(name, habitat)
    {
        this->wingspan = wingspan;
        this->canfly = canfly;
    }
    void displayDetails()
    {
        //
    }
};

class Reptile : virtual public Animal{
    bool isColdBlooded;
    bool hasScales;
public:
    bool get7()
    {
        return isColdBlooded;
    }
    bool get8()
    {
        return hasScales;
    }
    Reptile(string name, string habitat, bool isColdBlooded, bool hasScales) : Animal(name, habitat)
    {
        this->isColdBlooded = isColdBlooded;
        this->hasScales = hasScales;
    }
    void displayDetails()
    {
        //
    }
};

class Amphibian : public Mammal, public Bird, public Reptile{
public:
    Amphibian(string name, string habitat, string diettype, int numlegs, double wingspan, bool canfly, bool isColdBlooded, bool hasScales) : Animal(name, habitat), Mammal(name, habitat, diettype, numlegs), Bird(name, habitat, wingspan, numlegs), Reptile(name, habitat, isColdBlooded, hasScales)
    {

    }
    void displayDetails()
    {
        ofstream fout;
        fout.open("Amphibian.txt");
        fout << "Name : " << get1() << endl;
        fout << "Habitat : " << get2() << endl;
        fout << "Diet Type : " << get3() << endl;
        fout << "Number of Legs : " << get4() << endl;

        fout << "Wing Span : " << get5() << endl;
        fout << "Can fly ? : " << get6() << endl;
        fout << "Is Cold Blooded ? : " << get7() << endl;
        fout << "Has Scales ? : " << get8() << endl;
        fout.close();
    }
};

int main()
{
    Amphibian f("ABC", "DE", "water", 4, 7.35, true, true, false);
    f.displayDetails();

    return 0;
}

