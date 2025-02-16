#include "RNP.hpp"
#include <cstdlib>
#include <iostream>

int main(int argc, char** argv)
{
    if (argc == 1 || argc > 2)
    {
        std::cout << "Usage: [equation to resolve]\n";
        return EXIT_FAILURE;
    }
    RNP rnp;

    return rnp.solve(argv[1]);
}
