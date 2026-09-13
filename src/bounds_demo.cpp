#include <iostream>

int sumValues(const int* values, int size)
{
    int total = 0;

    for (int index = 0; index < size; ++index)
    {
        total += values[index];
    }

    return total;
}

int main()
{
    int values[3] = {10, 20, 30};
    int total = sumValues(values, 3);

    std::cout << "total = " << total << std::endl;
    return 0;
}
