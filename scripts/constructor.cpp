#include <iostream>

class Person{
    public:
        int age;
        Person() : age(0) { std::cout << "CTPR" << std::endl;};
        Person(int AGE) : age(AGE) {
            std::cout << "CTPR " << age << std::endl;
            }  
};

class Animal{
    public:
        Animal(int a){
            std::cout << "Neeraj " << a << std::endl;
        }
};

int main(){
    Person* p1 = new Person(120);
    Person* p2 = new Person();

    std::cout << p2->age << std::endl;

    Animal a1(0);

    delete p1;
    delete p2;
    return 0;
}