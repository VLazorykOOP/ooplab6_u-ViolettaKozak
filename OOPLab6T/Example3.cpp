#include "Lab6Example.h"
using namespace std;
namespace SpaceExample3 {
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
            cout << "Input name: ";
            is >> p.name;
            cout << "Input surename: ";
            is >> p.surname;
            cout << "Input age: ";
            is >> p.age;
            return is;
        }

        friend ostream& operator<<(ostream& os, const Person& p)
        {
            cout << "Name: " << p.name << ", Surename: " << p.surname << ", age" << p.age << endl;
            return os;
        }

        virtual void printInfo()
        {
            cout << "Name: " << name << ", Surename: " << surname << ", age: " << age << endl;
        }

    };

    class Woman : public Person
    {
    protected:
        string hasChildren;
    public:
        Woman(string name, string surname, int age, string hasChildren)
            : Person(name, surname, age), hasChildren(hasChildren) {}

        virtual ~Woman() {}

        friend istream& operator>>(istream& is, Woman& w)
        {
            is >> static_cast<Person&>(w);
            cout << "Has children? ";
            is >> w.hasChildren;
            return is;
        }

        friend ostream& operator<<(ostream& os, const Woman& w)
        {
            os << static_cast<const Person&>(w);
            os << "Has children? " << w.hasChildren << endl;
            return os;
        }

        virtual void printInfo()
        {
            cout << "Name: " << name << ", Surename: " << surname << ", age: " << age <<"Has children? " << hasChildren << endl;
        }

    };

    class Employee : public Person
    {
    protected:
        float salary;
    public:
        Employee(string name, string surname, int age, float salary)
            : Person(name, surname, age), salary(salary) {}
        virtual ~Employee() {}

        virtual void printInfo() {
            cout << "Name: " << name << ", Surename: " << surname << ", age: " << age << ", salary: " << salary << endl;
        }

        friend istream& operator>>(istream& is, Employee& e)
        {
            is >> static_cast<Person&>(e);
            cout << "Salary: ";
            is >> e.salary;
            return is;
        }

        friend ostream& operator<<(ostream& os, const Employee& e)
        {
            os << static_cast<const Person&>(e);
            os << "Salary: " << e.salary << endl;
            return os;
        }

    };

    class WomanEmployee : public Woman, Employee
    {
    protected:
        float upcomingMaternityLeave;
    public:
        WomanEmployee(string name, string surname, int age, float salary, string hasChildren, float upcomingMaternityLeave)
            :Woman(name, surname, age, hasChildren), Employee(name, surname, age, salary), upcomingMaternityLeave(upcomingMaternityLeave) {}
        virtual ~WomanEmployee() {}

        virtual void printInfo() {
            cout << "Name: " << Woman::name << ", Surename: " << Woman::surname << ", age: " << Woman::age << ", salary: " << salary << ", Has children? " << hasChildren << ", upcoming maternity leave: " << upcomingMaternityLeave << endl;
        }

        friend istream& operator>>(istream& is, WomanEmployee& we)
        {
            is >> static_cast<Employee&>(we);
            cout << "Has children? ";
            is >> we.hasChildren;
            cout << "Upcoming maternity leave: ";
            is >> we.upcomingMaternityLeave;
            return is;
        }

        friend ostream& operator<<(ostream& os, const WomanEmployee& we)
        {
            os << static_cast<const Employee&>(we);
            os << "Has children? " << we.hasChildren << endl;
            os << "Upcoming maternity leave: " << we.upcomingMaternityLeave << endl;
            return os;
        }
    };


    int main()
    {
        Person person("John", "Doe", 30);
        cout << person<<endl;

        Woman woman("Jane", "Doe", 28, "yes");
        cout << woman<<endl;

        Employee employee("Adam", "Smith", 35, 5000.0);
        cout << employee<<endl;

        WomanEmployee womanEmployee("Eve", "Smith", 33, 4500.0, "yes", 6.0);
        cout << womanEmployee<<endl;

        return 0;
    }

}
