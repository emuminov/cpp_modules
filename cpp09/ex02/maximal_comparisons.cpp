#include <iostream>
#include <cmath>
#include <cstdlib>

int F(int n)
{
    int sum = 0;
    for (int k = 1; k <= n; ++k) {
        double value = (3.0 / 4.0) * k;
        sum += static_cast<int>(ceil(log2(value)));
    }
    return sum;
}

int main(int argc, char** argv)
{
    if (argc < 2)
        return 1;

    int arg = atoi(argv[1]);
    std::cout << F(arg) << '\n';
}
