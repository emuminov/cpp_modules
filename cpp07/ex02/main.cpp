#include "Array.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

#define MAX_VAL 750
void subject_tests()
{
    Array<int> empty_arr;
    Array<int> numbers(MAX_VAL);
    Array<std::string> strings(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        strings[i] = value;
        mirror[i] = value;
    }
    // SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete[] mirror; //
}

void my_tests()
{
    try
    {
        Array<std::string> x(0);
        std::cout << x.size() << "\n";
        std::cout << x[0];
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << "\n";
    }
    Array<std::string> x(3);
    x[0] = "Hello";
    x[1] = " ";
    x[2] = "World";
    std::cout << x[0] << x[1] << x[2] << "\n";
    Array<std::string> y(x);
    std::cout << y[0] << y[1] << y[2] << "\n";
    Array<std::string> z(0);
    z = y;
    std::cout << z[0] << z[1] << z[2] << "\n";
    try
    {
        Array<std::string> x(3);
        x[0] = "Hello";
        x[1] = " ";
        x[2] = "World";
        x[3] = "ERROR";
        std::cout << x[0] << x[1] << x[2] << x[3] << "\n";
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << "\n";
    }
}

int main(void)
{
    subject_tests();
    my_tests();
    return 0;
}
