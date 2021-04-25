#include <cstdlib>
#include <ctime>
#include <iostream>

class Base {
  public:
    virtual ~Base() {};
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base* generate() {
    switch (rand() % 3) {
        case 0:
            std::cout << "Generated A instance" << std::endl;
            return new A();
        case 1:
            std::cout << "Generated B instance" << std::endl;
            return new B();
        case 2:
            std::cout << "Generated C instance" << std::endl;
            return new C();
        default:
            std::cout << "You suck at programming..." << std::endl;
            return NULL;
    }
}

void identify_from_pointer(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << 'A' << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << 'B' << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << 'C' << std::endl;
    } else {
        std::cout << "Stop right there, criminal scum!" << std::endl;
    }
}

void identify_from_reference(Base& p) {
    if (dynamic_cast<A*>(&p)) {
        std::cout << 'A' << std::endl;
    } else if (dynamic_cast<B*>(&p)) {
        std::cout << 'B' << std::endl;
    } else if (dynamic_cast<C*>(&p)) {
        std::cout << 'C' << std::endl;
    } else {
        std::cout << "Stop right there, criminal scum!" << std::endl;
    }
}

int main() {
    srand(time(NULL));

    {
        Base* a = new A();
        Base* b = new B();
        Base* c = new C();

        identify_from_pointer(a);
        identify_from_pointer(b);
        identify_from_pointer(c);

        std::cout << std::endl;

        identify_from_reference(*a);
        identify_from_reference(*b);
        identify_from_reference(*c);

        std::cout << std::endl;

        delete a;
        delete b;
        delete c;
    }

    {
        Base* base = generate();

        identify_from_pointer(base);
        identify_from_reference(*base);

        std::cout << std::endl;

        delete base;
    }

    {
        Base* base = generate();

        identify_from_pointer(base);
        identify_from_reference(*base);

        std::cout << std::endl;

        delete base;
    }

    {
        Base* base = generate();

        identify_from_pointer(base);
        identify_from_reference(*base);

        std::cout << std::endl;

        delete base;
    }

    {
        Base* base = new Base();

        identify_from_pointer(base);
        identify_from_reference(*base);

        std::cout << std::endl;

        delete base;
    }
}
