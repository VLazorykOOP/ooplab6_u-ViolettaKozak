#include "Lab6Example.h"
#include <iostream>
#include <string>
using namespace std;
namespace SpaceExample3 {
    // MultipleiInherance.cpp 
// Ієрархія типів складається з сутностей: 
// машина, пасажирський транспорт і автобус.
//


#include <iostream>
#include <string>

    using namespace std;

    class Person 
    {
    protected:
        string name;
        string surname;
        int age;
    public:
        Person(string name, string surname, int age)
            : name(name), surname(surname), age(age) {}
        virtual ~Person() {}

        friend istream& operator>>(istream& is, Person& p) 
        {
            cout << "Введіть ім'я: ";
            is >> p.name;
            cout << "Введіть вік: ";
            is >> p.age;
            return is;
        }

        friend ostream& operator<<(ostream& os, const Person& p) 
        {
            os << "Ім'я: " << p.name << ", вік: " << p.age << endl;
            return os;
        }

        virtual void printInfo() 
        {
            cout << "Ім'я: " << name << ", вік: " << age << endl;
        }

    };

    class Woman : public Person
    {
    protected:
        string hasChildren;
    public:
        Woman(string name, string surname, int age, string hasChildren)
            : Person(name, surname, age), hasChildren(hasChildren) {}

        virtual ~Woman(){}

        friend istream& operator>>(istream& is, Woman& w)
        {
            is >> static_cast<Person&>(w);
            cout << "Має дітей?: ";
            is >> w.hasChildren;
            return is;
        }

        friend ostream& operator<<(ostream& os, const Woman& w)
        {
            os << static_cast<const Person&>(w);
            os << "Має дітей?: " << w.hasChildren << endl;
            return os;
        }

        virtual void printInfo()
        {
            Person::printInfo();
            cout << "Має дітей? " << hasChildren << endl;
        }

    };

    class Employee: public Person
    {
    protected:
        float salary;
    public:
        Employee(string name, string surname, int age, float salary)
            : Person(name, surname, age), salary(salary) {}
        virtual ~Employee() {}

        virtual void printInfo() {
            cout << "Ім'я: " << name << ", прізвище: " << surname << ", вік: " << age << ", зарплата: " << salary << endl;
        }

        friend istream& operator>>(istream& is, Employee& e)
        {
            is >> static_cast<Person&>(e);
            cout << "Зарплата: ";
            is >> e.salary;
            return is;
        }

        friend ostream& operator<<(ostream& os, const Employee& e)
        {
            os << static_cast<const Person&>(e);
            os << "Зарплата: " << e.salary << endl;
            return os;
        }

    };

    class WomanEmployee : public Woman, Employee
    {
    protected:
        float upcomingMaternityLeave;
    public:
        WomanEmployee(string name, string surname, int age, float salary, string hasChildren, float upcomingMaternityLeave)
            : Person(name, surname, age), Woman(name, surname, age, hasChildren), Employee(name, surname, age, salary), upcomingMaternityLeave(upcomingMaternityLeave) {}
        virtual ~WomanEmployee() {}

        virtual void printInfo() {
            cout << "Ім'я: " << name << ", прізвище: " << surname << ", вік: " << age << ", зарплата: " << salary << ", має дітей: " << hasChildren << ", очікувані декретні: " << upcomingMaternityLeave << endl;
        }

        friend istream& operator>>(istream& is, WomanEmployee& we)
        {
            is >> static_cast<Employee&>(we);
            cout << "Має дітей: ";
            is >> we.hasChildren;
            cout << "Очікувані декретні: ";
            is << we.upcomingMaternityLeave;
            return is;
        }

        friend ostream& operator<<(ostream& os, const WomanEmployee& we)
        {
            os << static_cast<const Employee&>(we);
            os << "Має дітей? " << we.hasChildren << endl;
            os << "Очікувані декретні: " << we.upcomingMaternityLeave << endl;
            return os;
        }
    };


    int main()
    {
        Person person("John", "Doe", 30);
        cout << person;

        Woman woman("Jane", "Doe", 28, "yes");
        cout << woman;

        Employee employee("Adam", "Smith", 35, 5000.0);
        cout << employee;

        WomanEmployee womanEmployee("Eve", "Smith", 33, 4500.0, "yes", 6.0);
        cout << womanEmployee;

        return 0;
    }

}