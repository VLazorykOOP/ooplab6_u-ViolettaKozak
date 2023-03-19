#include "Lab6Example.h"
#include <iostream>

using namespace std;

class Animal {
protected:
    int age;
public:
    Animal(int a) : age(a) {}
    void move() {
        cout << "Animal is moving." << endl;
    }
};

class Miths {
protected:
    string name;
public:
    Miths(string n) : name(n) {}
    void usePower() {
        cout << "Miths are using their power." << endl;
    }
};

class MithicsAnimal : public Animal, public Miths {
protected:
    string origin;
public:
    MithicsAnimal(int a, string n, string o) : Animal(a), Miths(n), origin(o) {}
    void breatheFire() {
        cout << "MithicsAnimal is breathing fire." << endl;
    }
};

class God : virtual public Miths {
protected:
    string realm;
public:
    God(string n, string r) : Miths(n), realm(r) {}
    void createWorld() {
        cout << "God is creating the world." << endl;
    }
};

class Unicorn : public MithicsAnimal {
protected:
    int hornLength;
public:
    Unicorn(int a, string n, string o, int h) : MithicsAnimal(a, n, o), hornLength(h) {}
    void heal() {
        cout << "Unicorn is healing wounds." << endl;
    }
};

class Griffin : public Unicorn, public God, public MithicsAnimal {
protected:
    int wingspan;
public:
    Griffin(int a, string n, string o, int h, string r, int ws) : Unicorn(a, n, o, h), God(n, r), MithicsAnimal(a, n, o), wingspan(ws) {}
    void fly() {
        cout << "Griffin is flying." << endl;
    }
};

int main() {
    // Without virtual inheritance
    cout << "Size of Animal object: " << sizeof(Animal) << endl;
    cout << "Size of Miths object: " << sizeof(Miths) << endl;
    cout << "Size of MithicsAnimal object: " << sizeof(MithicsAnimal) << endl;
    cout << "Size of God object: " << sizeof(God) << endl;
    cout << "Size of Unicorn object: " << sizeof(Unicorn) << endl;
    cout << "Size of Griffin object: " << sizeof(Griffin) << endl;

    // With virtual inheritance
    cout << "Size of Animal object: " << sizeof(Animal) << endl;
    cout << "Size of Miths object: " << sizeof(Miths) << endl;
    cout << "Size of MithicsAnimal object: " << sizeof(MithicsAnimal) << endl;
    cout << "Size of God object: " << sizeof(God) << endl;
    cout << "Size of Unicorn object: " << sizeof(Unicorn) << endl;
    cout << "Size of Griffin object: " << sizeof(Griffin) << endl;

    return 0;
}
