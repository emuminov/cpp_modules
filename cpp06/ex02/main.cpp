#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>

Base* generate(void)
{
    static int times_called;
    srand(time(NULL));
    int res = rand();
    int i = 0;
    while (i < times_called)
    {
        res = rand();
        i++;
    }
    times_called++;

    switch (res % 3)
    {
    case 0:
        return new A;
    case 1:
        return new B;
    default:
        return new C;
    }
}

void identify(Base* p)
{
    Base* cast_try = dynamic_cast<A*>(p);
    if (cast_try)
    {
        std::cout << "A\n";
        return;
    }
    cast_try = dynamic_cast<B*>(p);
    if (cast_try)
    {
        std::cout << "B\n";
        return;
    }
    cast_try = dynamic_cast<C*>(p);
    if (cast_try)
    {
        std::cout << "C\n";
        return;
    }
    std::cout << "Base\n";
}

void identify(Base& p)
{
    try
    {
        Base& cast_try = dynamic_cast<A&>(p);
        (void)cast_try;
        std::cout << "A\n";
    }
    catch (std::exception&)
    {
    }
    try
    {
        Base& cast_try = dynamic_cast<B&>(p);
        (void)cast_try;
        std::cout << "B\n";
    }
    catch (std::exception&)
    {
    }
    try
    {
        Base& cast_try = dynamic_cast<C&>(p);
        (void)cast_try;
        std::cout << "C\n";
    }
    catch (std::exception&)
    {
    }
}

int main(void)
{
    for (int i = 0; i < 10; i++)
    {
        Base* base = generate();
        std::cout << "identify(Base* p):\n";
        identify(base);
        std::cout << "\n";
        std::cout << "identify(Base& p):\n";
        identify(*base);
        std::cout << "===\n";
        delete base;
    }
}
