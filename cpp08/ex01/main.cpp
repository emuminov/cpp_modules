#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

void subject_tests()
{
    Span sp(8);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(11);
    sp.addNumber(1);
    sp.addNumber(21);
    sp.addNumber(17);
    sp.addNumber(9);
    std::cout << sp << "\n";
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
}

void my_tests()
{
    int buf1[] = {0, 1, 2};
    std::vector<int> vec(buf1, buf1 + sizeof(buf1) / sizeof(int));
    Span sp(8);
    sp.insert(vec.begin(), vec.end());
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout << sp << "\n";
    int buf2[] = {8, 7, 6, 5, 4};
    sp.insert(buf2, buf2 + sizeof(buf2) / sizeof(int));
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout << sp << "\n";
    try
    {
        sp.addNumber(20);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << "\n";
    }
}

void big_test()
{
    const int size = 10000;
    srand(time(NULL));
    std::vector<int> vec(size);
    for (int i = 0; i < static_cast<int>(vec.size()); i++)
    {
        vec[i] = rand() % 1000000;
    }
    Span sp(size);
    sp.insert(vec.begin(), vec.end());
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout << sp << "\n";
}

int main(void)
{
    subject_tests();
    my_tests();
    big_test();
}
