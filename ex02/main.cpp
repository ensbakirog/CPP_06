#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base* generate(void) {
    int random = std::rand() % 3;
    switch (random) {
        case 0: return new A();
        case 1: return new B();
        case 2: return new C();
        default: return NULL;
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try 
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    try 
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    Base *ptr = generate();

    std::cout << "Trying idetify(Base& p)" << std::endl;
    identify(*ptr);

    std::cout << "Trying idetify(Base* p)" << std::endl;
    identify(ptr);

    delete ptr;
    return 0;
}